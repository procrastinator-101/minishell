/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:16:05 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/30 18:16:06 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	run_normal(t_scmd *scmd, int cmd_n)
{
	pid_t	f_pid;
	int		status;

	if (cmd_n > 0)
		builtin(scmd);
	else
	{
		f_pid = fork();
		if (f_pid < 0)
			printf("error");	// to check
		else if (f_pid == 0)
			exec_ve(scmd);
		else
			waitpid(f_pid, &status, 0);
	}
	return (0);
}
