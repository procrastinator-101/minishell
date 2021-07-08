/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_infork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:30:25 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/08 13:43:43 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	change_inout(t_scmd *scmd)
{
	if (scmd->previous)
	{
		dup2(scmd->previous->pipe[0], STDIN_FILENO);
		close(scmd->previous->pipe[0]);
	}
	if (scmd->next)
		dup2(scmd->pipe[1], STDOUT_FILENO);
	close(scmd->pipe[0]);
	close(scmd->pipe[1]);
	if (scmd->redirections)
	{
		if (redirection_dup(scmd->redirections) == 1)
			exit(1);
	}
}

static void	close_pipes(t_scmd *scmd)
{
	if (scmd->previous)
		close(scmd->previous->pipe[0]);
	if (!scmd->next)
		close(scmd->pipe[0]);
	close(scmd->pipe[1]);
}

int	run_infork(t_scmd *scmd)
{
	pid_t	f_pid;
	pid_t	ret;
	int		ex_st;
	int		signal;

	pipe(scmd->pipe);
	ex_st = 0;
	f_pid = fork();
	if (f_pid < 0)
	{
		print_error("fork", "Resource temporarily unavailable", 1);
		ft_manage_parsing_error(0);
	}
	else if (f_pid == 0)
	{
		ft_install_child_signal_handlers();
		change_inout(scmd);
		ex_st = builtin(scmd);
		exit(ex_st);
	}
	close_pipes(scmd);
	if (!scmd->next)
	{
		ret = 0;
		g_shell.ischild_signal = 1;
		signal = 0;
		while (ret != -1)
		{
			ret = waitpid(-1, &ex_st, 0);
			signal = catch_child_exitstatus(ex_st, f_pid, ret);
		}
		ft_manage_signal_output(signal);
		g_shell.ischild_signal = 0;
	}
	return (0);
}
