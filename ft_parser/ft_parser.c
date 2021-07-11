/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:08:22 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/11 19:53:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_parser(char *line, int size)
{
	int			error;
	t_token		*tokens;
	t_pipeline	*pipelines;

	tokens = ft_lexer(line, size, &error);
	if (error)
		return (error);
	pipelines = ft_get_cmd_tree(tokens, &error);
	if (error)
		return (error);
	error = ft_pipeline_finalise(pipelines);
	if (error)
		return (error);
	error = ft_pipeline_execute_heredocs(pipelines);
	if (error)
		return (error);
	error = start_execution(pipelines);
	return (error);
}
