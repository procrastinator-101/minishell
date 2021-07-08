/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_character_escape_sequence.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:06:52 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/04 17:18:28 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

char	*ft_handle_character_escape_sequence(char *cstring, int *len)
{
	*len = 2;
	if (cstring[1] == 'a')
		return (ft_strdup("\a"));
	if (cstring[1] == 'b')
		return (ft_strdup("\b"));
	if (cstring[1] == 'e')
		return (ft_strdup("\e"));
	if (cstring[1] == 'f')
		return (ft_strdup("\f"));
	if (cstring[1] == 'n')
		return (ft_strdup("\n"));
	if (cstring[1] == 'r')
		return (ft_strdup("\r"));
	if (cstring[1] == 't')
		return (ft_strdup("\t"));
	if (cstring[1] == 'v')
		return (ft_strdup("\v"));
	if (cstring[1] == '\\')
		return (ft_strdup("\\"));
	if (cstring[1] == '\'')
		return (ft_strdup("'"));
	if (cstring[1] == '?')
		return (ft_strdup("?"));
	return (ft_strdup("\""));
}
