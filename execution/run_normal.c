/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:16:05 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 15:25:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	run_normal(t_scmd *scmd, int cmd_n)
{
	pid_t	f_pid;
	int		signal;
	int		status;

	if (redirection_dup(scmd->redirections) == 1)
		return (1);
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
			ft_resettermios_attr();
			ft_install_child_signal_handlers();
			status = exec_ve(scmd);
			exit(status);
		}
		else
		{
			g_shell.ischild_signal = 1;
			waitpid(f_pid, &status, 0);
			g_shell.ischild_signal = 0;
			ft_settermios_attr();
			signal = catch_child_exitstatus(status, f_pid, f_pid);
			ft_manage_signal_output(signal);
		}
	}
	return (0);
}
