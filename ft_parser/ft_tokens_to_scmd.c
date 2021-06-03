/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokens_to_scmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:46:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/01 09:19:46 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_scmd	*ft_tokens_to_scmd(t_token **head, int *error)
{
	t_scmd	*scmd;
	t_token	*tail;
	t_token	*last;

	last = 0;
	scmd = 0;
	*error = 0;
	tail = *head;
	while (*head && !ft_iscntrl_operator(*head))
	{
		last = *head;
		*head = (*head)->next;
	}
	if (tail && !ft_iscntrl_operator(tail))
	{
		scmd = ft_scmd_create(tail);
		if (!scmd)
		{
			ft_token_clear(&tail);
			*error = EMAF;
			return (0);
		}
		last->next = 0;
	}
	return (scmd);
}
