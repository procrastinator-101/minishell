/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_extract_redirections.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:08:40 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 12:31:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_remove_extracted_tokens(t_token *tail, t_token *end)
{
	t_token	*next;

	while (tail && tail != end)
	{
		next = tail->next;
		if (ft_isrdc_operator(tail))
			free(tail->str);
		free(tail->meda);
		free(tail);
		tail = next;
	}
}

static t_redirection	*ft_extract_rdc(t_token **tokens, t_token **previous, \
						t_token **tail)
{
	t_token			*head;
	t_token			*next;
	t_redirection	*redirection;

	redirection = ft_redirection_create(0, 0, 0);
	if (!redirection)
		return (0);
	head = *tail;
	if (ft_isrdc_operand(head))
	{
		redirection->left_operand = head->str;
		head = head->next;
	}
	redirection->type = head->type;
	head = head->next;
	redirection->right_operand = head->str;
	redirection->isroperand_quoted = head->hasquotes;
	next = head->next;
	if (*previous)
		(*previous)->next = next;
	else
		*tokens = next;
	ft_remove_extracted_tokens(*tail, next);
	*tail = next;
	return (redirection);
}

int	ft_scmd_extract_redirections(t_scmd *scmd)
{
	t_token			*head;
	t_token			*previous;
	t_redirection	*rdc;

	previous = 0;
	head = scmd->tokens;
	while (head)
	{
		if (ft_isrdc_operator(head) || ft_isrdc_operand(head))
		{
			rdc = ft_extract_rdc(&(scmd->tokens), &previous, &head);
			if (!rdc)
				return (EMAF);
			ft_redirection_addback(&(scmd->redirections), rdc);
		}
		else
		{
			previous = head;
			head = head->next;
		}
	}
	return (0);
}
