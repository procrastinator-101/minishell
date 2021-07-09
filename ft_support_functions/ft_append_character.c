/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:03:39 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/04 15:07:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_support_functions.h"

char	*ft_append_character(char *str, char c)
{
	int		i;
	int		size;
	char	*ptr;

	if (!str)
		size = 0;
	else
		size = ft_strlen(str);
	ptr = malloc(size + 2);
	if (!ptr)
		return (0);
	i = -1;
	while (++i < size)
		ptr[i] = str[i];
	ptr[i] = c;
	ptr[i + 1] = 0;
	return (ptr);
}
