/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:57:40 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 16:34:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_remove_extracted_tokens(t_token *start, t_token *end)
{
	t_token	*next;

	while (start && start != end)
	{
		next = start->next;
		if (ft_isredirection(start))
			free(start->str);
		free(start->quotes);
		free(start);
		start = next;
	}
}

t_redirection	*ft_extract_redirection(t_token **tokens, t_token **previous, \
		t_token **tail)
{
	int				type;
	t_token			*head;
	char			*left;
	t_redirection	*redirection;

	head = *tail;
	if (ft_isrdc_operand(head))
	{
		left = head->str;
		head = head->next;
	}
	else
		left = 0;
	type = head->type;
	head = head->next;
	redirection = ft_redirection_create(head->str, right, type);
	if (!redirection)
		return (0);
	if (*previous)
		(*previous)->next = head->next;
	ft_remove_extracted_tokens(*tail, head->next);
	*tail = (*previous)->next;
	return (redirection);
}
