/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:14:19 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/29 19:15:19 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envp.h"

void	ft_envp_clear(t_envp **tail)
{
	t_envp	*next;
	t_envp	*head;

	head = *tail;
	while (head)
	{
		next = head->next;
		ft_envp_del(head);
		head = next;
	}
	*tail = 0;
}
