/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_normal_sequence.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:51:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/05 15:55:22 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_append_normal_sequence(char **str, char *cstring)
{
	int		ret;

	ret = 0;
	while (cstring[ret] && cstring[ret] != '\\')
		ret++;
	*str = ft_strnappend(*str, cstring, ret);
	if (!*str)
		return (-EMAF);
	return (ret);
}
