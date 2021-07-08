/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:07:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/29 19:11:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envp.h"

void	ft_envp_addback(t_envp **envp, t_envp *node)
{
	t_envp	*head;

	if (!*envp)
		*envp = node;
	else
	{
		head = *envp;
		while (head->next)
			head = head->next;
		head->next = node;
		node->previous = head;
	}
}
