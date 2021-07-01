/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:01:35 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/13 17:01:37 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	reset_in_out(void)
{
	dup2(g_shell.def_in, STDIN_FILENO);
	dup2(g_shell.def_out, STDOUT_FILENO);
}

static int	which_cmd(t_scmd *scmd)
{
	if (!ft_strcmp(scmd->args[0], "echo"))
			return (1);
		else if (!ft_strcmp(scmd->args[0], "cd"))
			return (2);
		else if (!ft_strcmp(scmd->args[0], "pwd"))
			return (3);
		else if (!ft_strcmp(scmd->args[0], "export"))
			return (4);
		else if (!ft_strcmp(scmd->args[0], "unset"))
			return (5);
		else if (!ft_strcmp(scmd->args[0], "env"))
			return (6);
		else if (!ft_strcmp(scmd->args[0], "exit"))
			return (7);
		else
			return (0);
}

void	start_execution(t_pipeline *pipeline)
{
	int		cmd_n;

	g_shell.def_in = dup(STDIN_FILENO);
	g_shell.def_out = dup(STDOUT_FILENO);
	while (pipeline->scmd)
	{
		cmd_n = which_cmd(pipeline->scmd);
		if (!pipeline->scmd->previous && !pipeline->scmd->next)
			run_normal(pipeline->scmd, cmd_n);
		else
			run_infork(pipeline->scmd);
		pipeline->scmd = pipeline->scmd->next;
		reset_in_out();
	}
}


// scmd.p and scmd.n = Null : run normal
// else : run in fork
// execve : run in fork
// done