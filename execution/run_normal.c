/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:16:05 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/06 18:01:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	catch_child_proc_exit_status(int wstatus)
{
	int	signal;

	if (WIFEXITED(wstatus))
		g_shell.scmd_status = WEXITSTATUS(wstatus);
	else if (WIFSIGNALED(wstatus))
	{
		signal = WTERMSIG(wstatus);
		if (signal == SIGQUIT)
		{
			ft_putstr_fd("Quit: ", 2);
			ft_putnbr_fd(signal, 2);
			ft_putstr_fd("\n", 2);
		}
		g_shell.scmd_status = signal + 128;
	}
}

int	run_normal(t_scmd *scmd, int cmd_n)
{
	pid_t	f_pid;
	int		status;

	if (redirection_dup(scmd->redirections) == 1)
	{
		g_shell.scmd_status = 1;
		return (1);
	}
	if (cmd_n > 0)
		builtin(scmd);
	else
	{
		f_pid = fork();
		if (f_pid < 0)
		{
			print_error("fork", "Resource temporarily unavailable", 1);
			ft_manage_parsing_error(0); // to fix
		}
		else if (f_pid == 0)
		{
			ft_install_child_signal_handlers();
			status = exec_ve(scmd);
			exit(status);
		}
		else
		{
			g_shell.ischild_signal = 1;
			waitpid(f_pid, &status, 0);
			g_shell.ischild_signal = 0;
			catch_child_proc_exit_status(status);
		}
	}
	return (0);
}
