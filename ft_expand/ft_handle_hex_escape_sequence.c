/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_escape_sequence.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:27:51 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 09:59:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

char	*ft_handle_hex_escape_sequence(char *cstring, int *len)
{
	int		i;
	char	c;
	char	*str;

	i = 3;
	while (i < 4 && cstring[i] && ft_strchr("0123456789abcdef", cstring[i]))
		i++;
	*len = i;
	str = ft_strndup(cstring + 2, i - 2);
	if (!str)
		return (0);
	c = ft_atoi_base(str, "0123456789abcdef");
	free(str);
	return (ft_append_character(0, c));
}
