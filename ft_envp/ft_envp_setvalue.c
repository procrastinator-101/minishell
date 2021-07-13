/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_setvalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:44:18 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 12:50:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envp.h"

static char	*checkalloc(char *str)
{
	if (str)
		return (str);
	ft_display_error_msg(0);
	ft_putstr_fd("MALLOC", 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	exit(1);
}

void	ft_envp_setvalue(t_envp *envp, char *name, char *value)
{
	t_envp	*head;
	t_envp	*node;

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
		node = ft_envp_create(checkalloc(ft_strdup(name)), value, 1);
		ft_envp_addback(&envp, node);
	}
}
