/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_scmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:22:59 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 14:27:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static void	ft_update_tokens(t_token **tokens, t_token **previous, t_token *head, \
			t_token *next)
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

int	ft_expand_scmd(t_scmd *scmd)
{
	int		error;
	t_token	*head;
	t_token	*next;
	t_token	*previous;

	head = scmd->tokens;
	previous = 0;
	while (head)
	{
		next = head->next;
		head->next = 0;
		head = ft_expand_token(head, &error);
		ft_update_tokens(&(scmd->tokens), &previous, head, next);
		if (error)
			return (error);
		head = next;
	}
	return (0);
}
