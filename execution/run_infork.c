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

int	run_infork(t_scmd *scmd)
{
	pid_t	f_pid;
	int		ex_st;

	pipe(scmd->pipe);
	f_pid = fork();
	if (f_pid < 0)
		printf("error");	// to check
	if (f_pid == 0)
	{
		ex_st = builtin(scmd);
		exit(ex_st);
	}
	else
	{
		if (!scmd->next)
		{
			waitpid(f_pid, &g_shell.scmd_status, 0);	// to check
		}
		else
			wait(NULL);
	}
	return (0);
}
