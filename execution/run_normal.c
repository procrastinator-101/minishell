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
			ft_manage_parsing_error(0);
		}
		else if (f_pid == 0)
		{
			status = exec_ve(scmd);
			exit(status);
		}
		else
			waitpid(f_pid, &status, 0);
	}
	return (0);
}
