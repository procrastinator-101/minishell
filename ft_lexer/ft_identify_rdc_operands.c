/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify_rdc_operands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:08:15 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 17:55:57 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static void	ft_handle_blank_tokens(t_token **tokens, t_token *previous, \
			t_token *token, t_token *next)
{
	ft_token_del(token);
	if (!previous)
		*tokens = next;
	else
		previous->next = next;
}

void	ft_identify_rdc_operands(t_token **tokens)
{
	t_token	*next;
	t_token	*token;
	t_token	*previous;

	previous = 0;
	token = *tokens;
	while (token)
	{
		next = token->next;
		if (ft_isblank(token))
			ft_handle_blank_tokens(tokens, previous, token, next);
		else
		{
			if (ft_isword(token) && previous && ft_isrdc_operator(previous))
				token->type = RDC_ROPERAND;
			previous = token;
		}
		token = next;
	}
}
