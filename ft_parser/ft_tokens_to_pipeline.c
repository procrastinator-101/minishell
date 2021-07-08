/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_to_pipeline.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 17:36:41 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/01 09:19:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static t_pipeline	*ft_update_pipeline(t_pipeline *pipeline, t_token **tail, \
					int *error)
{
	t_scmd	*scmd;

	scmd = ft_tokens_to_scmd(tail, error);
	if (*error)
	{
		ft_pipeline_del(pipeline);
		return (0);
	}
	if (!pipeline)
		pipeline = ft_pipeline_create(scmd, NEW_LINE);
	else
		ft_scmd_addback(&(pipeline->scmd), scmd);
	if (!pipeline)
	{
		*error = EMAF;
		ft_scmd_clear(&scmd);
		ft_token_clear(tail);
		return (0);
	}
	return (pipeline);
}

t_pipeline	*ft_tokens_to_pipeline(t_token **tail, int *error)
{
	char		type;
	t_token		*next;
	t_pipeline	*pipeline;

	*error = 0;
	pipeline = 0;
	while (*tail)
	{
		pipeline = ft_update_pipeline(pipeline, tail, error);
		if (*error)
			return (0);
		if (!*tail)
			return (pipeline);
		type = (*tail)->type;
		if (type != PIPE)
			pipeline->cntrl_operator = type;
		next = (*tail)->next;
		ft_token_del(*tail);
		*tail = next;
		if (type != PIPE)
			return (pipeline);
	}
	return (pipeline);
}
