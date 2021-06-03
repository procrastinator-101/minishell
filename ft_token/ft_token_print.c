/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:42:10 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 21:02:20 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

void	ft_token_print(t_token *tail)
{
	t_token	*head;

	head = tail;
	while (head)
	{
		printf("------------------ TOKEN -----------------\n");
		printf("%s\n", head->str);
		printf("%s\n", head->quotes);
		ft_token_print_type(head->type);
		head = head->next;
		printf("------------------------------------------\n");
	}
}
