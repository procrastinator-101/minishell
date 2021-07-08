/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_octal_escape_sequence.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:35:12 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 10:03:13 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

char	*ft_handle_octal_escape_sequence(char *cstring, int *len)
{
	int		i;
	char	c;
	char	*str;

	i = 2;
	while (i < 4 && cstring[i] && ft_strchr("01234567", cstring[i]))
		i++;
	*len = i;
	str = ft_strndup(cstring + 1, i - 1);
	if (!str)
		return (0);
	c = ft_atoi_base(str, "01234567");
	free(str);
	return (ft_append_character(0, c));
}
