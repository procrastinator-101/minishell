/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_escape_sequence.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:02:21 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 11:09:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static char	*ft_get_escape_sequence(char *cstring, int *ret)
{
	char	c;

	*ret = 2;
	c = cstring[1];
	if (c == 'c')
		return (ft_handle_control_escape_sequence(cstring, ret));
	else if (c == 'x' && ft_strichr("0123456789abcdef", cstring[2]) >= 0)
		return (ft_handle_hex_escape_sequence(cstring, ret));
	else if (c >= '0' && c <= '7')
		return (ft_handle_octal_escape_sequence(cstring, ret));
	else if (c == 'a' || c == 'b' || c == 'e' || c == 'f' || c == 'n')
		return (ft_handle_character_escape_sequence(cstring, ret));
	else if (c == 'r' || c == 't' || c == 'v' || c == '\\' || c == '\'')
		return (ft_handle_character_escape_sequence(cstring, ret));
	else if (c == '?' || c == '"')
		return (ft_handle_character_escape_sequence(cstring, ret));
	return (ft_strndup(cstring, 2));
}

int	ft_append_escape_sequence(char **str, char *cstring)
{
	int		ret;
	char	*ptr;

	ptr = ft_get_escape_sequence(cstring, &ret);
	if (!ptr)
	{
		free(*str);
		*str = 0;
		return (-EMAF);
	}
	*str = ft_strnappend(*str, ptr, ft_strlen(ptr));
	free(ptr);
	if (str)
		return (ret);
	return (-EMAF);
}
