/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_infork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:30:25 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 20:22:22 by yarroubi         ###   ########.fr       */
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

int	run_infork(t_scmd *scmd)
{
	pid_t	f_pid;
	pid_t	ret;
	int		tmp;
	int		ex_st;
	int		signal;

	pipe(scmd->pipe);
	ex_st = 0;
	if (change_inout(scmd) == 1)
		return (1);
	printf("out\n");
	f_pid = fork();
	if (f_pid < 0)
	{
		print_error("fork", "Resource temporarily unavailable", 1);
		ft_manage_parsing_error(0);
	}
	else if (f_pid == 0)
	{
		ft_resettermios_attr();
		ft_install_child_signal_handlers();
		close_inout_child(scmd);
		ex_st = builtin(scmd);
		exit(ex_st);
	}
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
	return (0);
}
