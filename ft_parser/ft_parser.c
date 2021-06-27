/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:08:22 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 19:41:04 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_parser(char *line, int size)
{
	int			error;
	t_token		*tokens;
	t_pipeline	*pipeline;
	t_pipeline	*pipelines;

	tokens = ft_lexer(line, size, &error);
	if (error)
		return (error);
	pipelines = ft_get_cmd_tree(tokens, &error);
	if (error)
		return (error);
	pipeline = pipelines;
	while (pipeline)
	{
		error = ft_pipeline_finalise(pipeline);
		if (error)
			return (error);
		pipeline = pipeline->next;
	}
	ft_pipeline_print(pipelines);
	/**/
	start_execution(pipelines);
	//ft_pipeline_clear(&pipelines);
	return (error);
}
