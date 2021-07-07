/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:01:35 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/06 18:52:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	which_cmd(t_scmd *scmd)
{
	if (scmd->args && scmd->args[0])
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
	return (-1);
}

void	start_execution(t_pipeline *pipeline)
{
	int			ret;
	int			status;
	int			cmd_n;
	t_scmd		*scmd;
	t_pipeline	*head;

	def_in_out();
	head = pipeline;
	while (head)
	{
		scmd = head->scmd;
		ret = 0;
		while (scmd)
		{
			cmd_n = which_cmd(scmd);
			if (!scmd->previous && !scmd->next)
				status = run_normal(scmd, cmd_n);
			else
				status = run_infork(scmd);
			ret |= status;
			scmd = scmd->next;
			reset_in_out();
		}
		// if (ret && WIFSIGNALED(ret)) 				// try rdfg < rsgf // you will get an extra "/n"
		// 	write(1, "\n", 1);
		head = head->next;
		g_shell.pipeline_status = g_shell.scmd_status;
	}
	ft_pipeline_clear(&pipeline);
}
