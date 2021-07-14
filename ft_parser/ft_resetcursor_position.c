/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetcursor_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:20:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 13:14:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static int	ft_reposition_cursor(int x, int y, int offset, char *termcap)
{
	int		col;
	int		row;
	int		tmp;

	col = tgetnum("co");
	if (col == -1)
		return (1);
	row = tgetnum("li");
	if (row == -1)
		return (1);
	tmp = x;
	x = (x + offset) % col - 1;
	y += (tmp + offset) / col - 1 + g_shell.issignal;
	if (y >= row - 1)
		y = row - 2;
	if (x < 1)
		x = 1;
	if (y < 0)
		y = 0;
	termcap = tgoto(termcap, x, y);
	if (!termcap)
		return (1);
	write(STDOUT_FILENO, termcap, ft_strlen(termcap));
	return (0);
}

int	ft_resetcursor_position(int offset)
{
	int		x;
	int		y;
	int		ret;
	char	*termcap;

	x = 0;
	y = 0;
	ret = ft_getcursor_position(&x, &y);
	if (ret)
		return (1);
	termcap = tgetstr("cm", 0);
	if (!termcap)
		return (1);
	if (x == 1 && y == 2)
	{
		g_shell.x = 1;
		g_shell.y = 0;
	}
	x = g_shell.x;
	y = g_shell.y;
	return (ft_reposition_cursor(x, y, offset, termcap));
}
