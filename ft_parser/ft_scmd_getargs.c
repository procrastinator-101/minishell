/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_getargs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:00:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 17:28:11 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_scmd_getargs(t_scmd *scmd)
{
	int		size;
	t_token	*head;
	t_token	*next;

	size = ft_token_size(scmd->tokens) + 1;
	scmd->args = malloc(size * sizeof(char *));
	if (!scmd->args)
		return (EMAF);
	size = 0;
	head = scmd->tokens;
	while (head)
	{
		next = head->next;
		scmd->args[size++] = head->str;
		head->str = 0;
		ft_token_del(head);
		head = next;
	}
	scmd->tokens = 0;
	scmd->args[size] = 0;
	return (0);
}
