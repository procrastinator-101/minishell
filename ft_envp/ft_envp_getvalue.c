/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_getvalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:56:35 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 18:24:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envp.h"

char	*ft_envp_getvalue(t_envp *envp, char *name)
{
	t_envp	*head;

	head = envp;
	while (head)
	{
		if (!ft_strcmp(head->name, name))
			return (head->value);
		head = head->next;
	}
	return (0);
}
