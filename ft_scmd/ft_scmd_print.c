/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:26:44 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 18:02:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scmd.h"

void	ft_scmd_print(t_scmd *tail)
{
	int		i;
	t_scmd	*head;

	head = tail;
	while (head)
	{
		printf("====================== SCMD ======================\n");
		i = -1;
		ft_token_print(head->tokens);
		while (head->args && head->args[++i])
			printf("args[%d] = %s|\n", i, head->args[i]);
		ft_redirection_print(head->redirections);
		head = head->next;
		printf("==================================================\n");
	}
}
