/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_backslash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:59:23 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/25 16:02:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_process_backslash(char *line, char *quotes, int index)
{
	quotes[index++] = NON_QUOTED;
	if (!line[index])
		return (ENCQ);
	quotes[index++] = QUOTED;
	return (index);
}
