/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_heredocs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:40:42 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/11 19:17:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_pipeline_execute_heredocs(t_pipeline *pipelines)
{
	int				id;
	int				ret;
	t_pipeline		*head;

	id = -1;
	ret = 0;
	head = pipelines;
	while (head)
	{
		ret = ft_scmd_execute_heredocs(head->scmd, &id);
		if (ret)
			return (ret);
		head = head->next;
	}
	return (ret);
}
