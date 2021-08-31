/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_filename_expansion.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:55:16 by youness           #+#    #+#             */
/*   Updated: 2021/08/31 20:55:18 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static void	ft_update_tokens(t_token **tokens, t_token **previous, t_token \
			*head, t_token *next)
{
	if (!head)
	{
		if (*previous)
			(*previous)->next = next;
		else
			*tokens = next;
		return ;
	}
	if (*previous)
		(*previous)->next = head;
	else
		*tokens = head;
	while (head->next)
		head = head->next;
	*previous = head;
	head->next = next;
}

int ft_handle_filename_expansion(t_token **tokens)
{
    int		error;
	t_token	*head;
	t_token	*next;
	t_token	*previous;

	head = *tokens;
	previous = 0;
	while (head)
	{
		next = head->next;
		head->next = 0;
		head = ft_filename_expansion(head, &error);
		ft_update_tokens(tokens, &previous, head, next);
		if (error)
			return (error);
		head = next;
	}
	return (0);
}
