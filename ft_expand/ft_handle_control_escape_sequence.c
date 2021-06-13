/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_control_escape_sequence.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:26:37 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/04 17:43:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

char	*ft_handle_control_escape_sequence(char *cstring, int *len)
{
	char	c;

	*len = 3;
	c = cstring[2] % 32;
	if (!c)
		return (ft_strdup(""));
	return (ft_append_character(0, c));
}
