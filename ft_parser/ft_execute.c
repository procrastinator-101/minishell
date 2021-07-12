/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:52:36 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/12 13:07:44 by yarroubi         ###   ########.fr       */
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
		error = ft_pipeline_execute_heredocs(pipelines);
		if (error)
			return (error);
		error = start_execution(head);
		if (error)
			break ;
		head = head->next;
	}
	if (error)
		ft_pipeline_clear(&pipelines);
	return (error);
}
