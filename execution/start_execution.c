/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:01:35 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/08 13:29:39 by yarroubi         ###   ########.fr       */
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
	int			cmd_n;
	t_scmd		*scmd;
	t_pipeline	*head;

	def_in_out();
	head = pipeline;
	while (head)
	{
		scmd = head->scmd;
		while (scmd)
		{
			cmd_n = which_cmd(scmd);
			if (!scmd->previous && !scmd->next)
				run_normal(scmd, cmd_n);
			else
				run_infork(scmd);
			scmd = scmd->next;
			reset_in_out();
		}
		head = head->next;
		g_shell.pipeline_status = g_shell.scmd_status;
	}
	ft_pipeline_clear(&pipeline);
}
