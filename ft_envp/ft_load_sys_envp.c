/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_sys_envp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:20:38 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 18:28:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envp.h"

t_envp	*ft_load_sys_envp(char **sys_envp, int *error)
{
	int		i;
	t_envp	*envp;
	t_envp	*node;

	i = -1;
	envp = 0;
	*error = 0;
	while (sys_envp[++i])
	{
		node = ft_char_to_envp(sys_envp[i], error);
		if (*error)
		{
			ft_envp_clear(&envp);
			return (0);
		}
		ft_envp_addback(&envp, node);
	}
	return (envp);
}
