/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:22:41 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 17:20:20 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

void	ft_redirection_print(t_redirection *tail)
{
	t_redirection	*head;

	head = tail;
	while (head)
	{
		printf("_______________________________________\n");
		if (head->left_operand)
			printf("letf = %s\n", head->left_operand);
		if (head->right_operand)
			printf("right = %s\n", head->right_operand);
		ft_token_print_type(head->type);
		printf("_______________________________________\n");
		head = head->next;
	}
}
