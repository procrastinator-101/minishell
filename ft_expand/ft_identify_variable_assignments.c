/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify_variable_assignments.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:15:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 19:39:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

void	ft_identify_variable_assignments(t_token *tokens)
{
	int		tmp;
	int		equal;
	t_token	*head;

	head = tokens;
	while (head && head->type != WORD)
		head = head->next;
	tmp = ft_iscmd_varassignable(head);
	if (!tmp)
		return ;
	head = tokens;
	while (head)
	{
		if (head->type == WORD)
		{
			equal = ft_strichr(head->str, '=');
			if (equal >= 0)
			{
				while (head->str[++equal])
					head->meda[equal].va = 1;
			}
		}
		head = head->next;
	}
}
