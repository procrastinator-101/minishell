/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_setvalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:44:18 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/02 13:44:22 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envp.h"

void	ft_envp_setvalue(t_envp *envp, char *name, char *value)
{
	t_envp	*head;
    t_envp  *node;

	head = envp;
	while (head)
	{
		if (!ft_strcmp(head->name, name))
		{
            free(head->value);
            head->value = value;
            return ;
        }
		head = head->next;
	}
    if (!head)
    {
        node = ft_envp_create(ft_strdup(name), value, 1);
        ft_envp_addback(&envp, node);
    }
}
