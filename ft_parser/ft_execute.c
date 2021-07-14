/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:52:36 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 15:26:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_execute(t_pipeline *pipelines)
{
	int			error;
	t_pipeline	*head;

	error = 0;
	head = pipelines;
	while (head)
	{
		error = ft_pipeline_finalise(head);
		if (error)
			break ;
		g_shell.heredoc_status = 0;
		error = ft_pipeline_execute_heredocs(pipelines);
		if (g_shell.heredoc_status == 2)
			g_shell.count = 0;
		if (error)
			return (error);
		error = start_execution(head);
		if (error)
			break ;
		head = head->next;
	}
	ft_pipeline_clear(&pipelines);
	return (error);
}
