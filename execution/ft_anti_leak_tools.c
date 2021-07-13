/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anti_leak_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:00:17 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/07 18:00:23 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	free_2d(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
		free(tabl[i++]);
	free(tabl);
}

char	*join_free_s1(char *s1, char *s2)
{
	char	*str;

	str = checkalloc(ft_strjoin(s1, s2));
	free(s1);
	return (str);
}

char	*join_free_all(char *s1, char *s2)
{
	char	*str;

	str = checkalloc(ft_strjoin(s1, s2));
	free(s1);
	free(s2);
	return (str);
}

char	*free_return(char *to_ret, char *to_free)
{
	free(to_free);
	return (to_ret);
}
