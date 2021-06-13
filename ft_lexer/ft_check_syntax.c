/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:36:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 09:49:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_check_syntax(t_token *tokens)
{
	t_token	*head;
	t_token	*next;

	if (!tokens)
		return (0);
	head = tokens;
	if (ft_isoperator(head) && !ft_isrdc_operator(head))
		return (ECCO + (head->type << 8));
	while (head)
	{
		next = head->next;
		if (!next && (ft_isrdc_operator(head) || head->type == PIPE))
			return (ECCO + (NEW_LINE << 8));
		else if (next && ft_isoperator(head) && ft_isoperator(next))
		{
			if (ft_isrdc_operator(head))
				return (ECCO + (next->type << 8));
			else if (ft_iscntrl_operator(next) && next->type != NEW_LINE)
				return (ECCO + (next->type << 8));
		}
		head = next;
	}
	return (0);
}
