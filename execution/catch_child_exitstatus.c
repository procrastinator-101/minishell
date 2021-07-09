/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_child_exitstatus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:02:22 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/08 14:58:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	catch_child_exitstatus(int wstatus, int lastpid, int pid)
{
	int	signal;

	signal = 0;
	if (WIFEXITED(wstatus))
	{
		if (pid == lastpid)
			g_shell.scmd_status = WEXITSTATUS(wstatus);
	}
	else if (WIFSIGNALED(wstatus))
	{
		signal = WTERMSIG(wstatus);
		if (pid == lastpid)
			g_shell.scmd_status = 128 + signal;
		else if (signal == SIGQUIT)
			return (0);
	}
	return (signal);
}
