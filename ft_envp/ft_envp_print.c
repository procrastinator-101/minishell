/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:16:34 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 18:29:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envp.h"

void	ft_envp_print(t_envp *tail)
{
	t_envp	*head;

	head = tail;
	while (head)
	{
		printf("---------------------------------------\n");
		printf("name = %s\n", head->name);
		printf("value = %s\n", head->value);
		printf("---------------------------------------\n");
		head = head->next;
	}
}
