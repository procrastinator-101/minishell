/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_infork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:30:25 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/30 18:30:27 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	change_inout(t_scmd *scmd)
{
	if (scmd->previous)
		dup2(scmd->previous->pipe[0], STDIN_FILENO);
	if (scmd->next)
		dup2(scmd->pipe[1], STDOUT_FILENO);
	close(scmd->pipe[0]);
	close(scmd->pipe[1]);
}

int	run_infork(t_scmd *scmd)
{
	pid_t	f_pid;
	int		ex_st;

	pipe(scmd->pipe);
	f_pid = fork();
	if (f_pid < 0)
		printf("error");	// to check
	else if (f_pid == 0)
	{
		change_inout(scmd);
		ex_st = builtin(scmd);
		exit(ex_st);
	}
	else
	{
		if (!scmd->next)
		{
			while (waitpid(f_pid, &ex_st, 0) == 0)	// to check
				;
		}
		else
			wait(NULL);
	}
	if (scmd->previous)
		close(scmd->previous->pipe[0]);
	if (!scmd->next)
		close(scmd->pipe[0]);
	close(scmd->pipe[1]);
	return (0);
}
