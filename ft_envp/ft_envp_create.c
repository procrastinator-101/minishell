/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 19:11:56 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/29 19:14:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envp.h"

t_envp	*ft_envp_create(char *name, char *value, int isenv)
{
	t_envp	*envp;

	envp = malloc(sizeof(t_envp));
	if (!envp)
		return (0);
	envp->name = name;
	envp->value = value;
	envp->isenv = isenv;
	envp->next = 0;
	envp->previous = 0;
	return (envp);
}
