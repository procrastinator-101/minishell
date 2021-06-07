/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_backslash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:59:23 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 10:59:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_process_backslash(char *line, char *quotes, int index)
{
	quotes[index++] = UNQUOTED;
	if (!line[index])
		return (-ENCQ);
	quotes[index++] = ESCAPED;
	return (index);
}
