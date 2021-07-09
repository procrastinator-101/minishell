/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:48:01 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/01 09:19:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_pipeline	*ft_get_cmd_tree(t_token *tokens, int *error)
{
	t_token		*head;
	t_pipeline	*pipeline;
	t_pipeline	*pipelines;

	*error = 0;
	head = tokens;
	pipelines = 0;
	while (head)
	{
		pipeline = ft_tokens_to_pipeline(&head, error);
		if (*error)
		{
			ft_pipeline_clear(&pipelines);
			return (0);
		}
		ft_pipeline_addback(&pipelines, pipeline);
	}
	return (pipelines);
}
