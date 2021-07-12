/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetcursor_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:20:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/12 15:13:57 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_resetcursor_position(int offset)
{
	int		ret;
	char	*termcap;

	ret = tgetent(NULL, g_shell.terminal);
	if (ret < 1)
		exit(EXIT_FAILURE);//to eliminate
	termcap = tgetstr("up", NULL);
	write(STDOUT_FILENO, termcap, ft_strlen(termcap));
	termcap = tgetstr("nd", NULL);
	printf("offset = %d\n", offset);
	while (offset--)
		write(STDOUT_FILENO, termcap, ft_strlen(termcap));
}
