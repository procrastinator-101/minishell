/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:08:22 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 16:15:08 by yarroubi         ###   ########.fr       */
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
	if (!tokens)
	{
		g_shell.scmd_status = 0;
		g_shell.pipeline_status = 0;
		return (0);
	}
	pipelines = ft_get_cmd_tree(tokens, &error);
	if (error)
		return (error);
	return (ft_execute(pipelines));
}
