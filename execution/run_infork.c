/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_infork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:30:25 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/11 20:32:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	close_inout_child(t_scmd *scmd)
{
	if (scmd->previous)
		close(scmd->previous->pipe[0]);
	close(scmd->pipe[0]);
	close(scmd->pipe[1]);
}

static int	change_inout(t_scmd *scmd)
{
	if (scmd->previous)
	{
		dup2(scmd->previous->pipe[0], STDIN_FILENO);
		close(scmd->previous->pipe[0]);
	}
	if (scmd->next)
		dup2(scmd->pipe[1], STDOUT_FILENO);
	if (!scmd->next)
		close(scmd->pipe[0]);
	close(scmd->pipe[1]);
	if (scmd->redirections)
	{
		if (redirection_dup(scmd->redirections) == 1)
			return (1);
	}
	return (0);
}

static void	close_pipes(t_scmd *scmd)
{
	if (scmd->previous)
		close(scmd->previous->pipe[0]);
	if (!scmd->next)
		close(scmd->pipe[0]);
	close(scmd->pipe[1]);
}

static void	parent_work(t_scmd *scmd, pid_t f_pid)
{
	pid_t	ret;
	int		signal;
	int		tmp;
	int		ex_st;

	close_pipes(scmd);
	reset_in_out();
	if (!scmd->next)
	{
		ret = 0;
		g_shell.ischild_signal = 1;
		signal = 0;
		while (1)
		{
			ret = waitpid(-1, &ex_st, 0);
			if (ret == -1)
				break ;
			tmp = catch_child_exitstatus(ex_st, f_pid, ret);
			if (tmp)
				signal = tmp;
		}
		ft_manage_signal_output(signal);
		g_shell.ischild_signal = 0;
		ft_settermios_attr();
	}
}

int	run_infork(t_scmd *scmd)
{
	pid_t	f_pid;
	int		ex_st;

	if (pipe(scmd->pipe) < 0)
		exit_failure("pipe");
	ex_st = 0;
	if (change_inout(scmd) == 1)
		return (1);
	f_pid = fork();
	if (f_pid < 0)
		exit_failure("fork");
	else if (f_pid == 0)
	{
		ft_resettermios_attr();
		ft_install_child_signal_handlers();
		close_inout_child(scmd);
		ex_st = builtin(scmd);
		exit(ex_st);
	}
	parent_work(scmd, f_pid);
	return (0);
}
