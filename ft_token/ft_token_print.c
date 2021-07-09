/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:42:10 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 11:35:52 by yarroubi         ###   ########.fr       */
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
		if (head->str)
			printf("%s\n", head->str);
		if (head->meda)
			ft_metadata_print(head->meda);
		ft_token_print_type(head->type);
		head = head->next;
		printf("------------------------------------------\n");
	}
}
