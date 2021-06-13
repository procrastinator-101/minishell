/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_cmd_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:21:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/30 19:46:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static t_pipeline	*ft_get_pipeline(t_token **tail, int *error)
{
	t_scmd		*scmd;
	t_token		*head;
	t_token		*next;
	t_pipeline	*pipeline;
	
	*error = 0;
	head = tail;
	pipeline = 0;
	while (head)
	{
		scmd = ft_tokens_to_cmd(&head, error);
		if (*error)
		{
			ft_pipeline_harddel(pipeline);
			break ;
		}
		if (!pipeline)
			pipeline = ft_pipeline_create(scmd, NEW_LINE);
		if (!pipeline)
		{
			ft_scmd_clear(&scmd);
			ft_token_clear(&head);
			break ;
		}
		ft_scmd_addback(pipeline->scmd, scmd);
		if (!head)
			break ;
		if (head && head->type != PIPE)
			pipeline->type = head->type;
		next = head;
		if (head)
			ft_token_del(head);
	}
	*tail = head;
	return (pipeline);
}

t_pipeline	*ft_construct_cmd_tree(t_token *tokens, int *error)
{
	t_pipeline	*pipelines;

	tail = tokens;
	head = tokens;
	pipelines = 0;
	while (head)
	{
		head = ft_get_pipeline(&pipelines, head);
		head = next;
	}
}
