/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_termcaps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:04:12 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/25 11:13:38 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_handle_termcaps(char *termcap)
{
	int		idx;
	int		error;

	idx = 0;
	while (++idx < 3)
	{
		error  = read(1, termcap + idx, 1);
		if (error < 0)
			return (error);
		if (idx == 1 && strncmp(termcap, "^[", 2))
			return (INVALID_TERMCAP);
		else if (idx == 2 && !ft_isin(termcap[idx], "ABCD"))
			return (INVALID_TERMCAP);
	}
	/*
	for (int i = 0; i < 3; i++)
		printf("c = %c\n", buffer[i]);
	*/
	printf("\n\ntermcap\n\n");
	if (!strncmp(buffer, "[A", 2))//ft_strncmp
		printf("up\n");
	else if (!strncmp(buffer, "[B", 2))
		printf("down\n");
	else if (!strncmp(buffer, "[C", 2))
		printf("right\n");
	else if (!strncmp(buffer, "[D", 2))
		printf("left\n");
	return (0);
}
