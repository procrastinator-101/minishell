/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetcursor_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:20:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 16:02:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_resetcursor_position(int offset)
{
	int		ret;
	char	*right;

	if (!offset)
		ret = offset;
	ret = tgetent(NULL, g_shell.terminal);
	if (ret == -1)
		return (ETERMINFO);
	else if (!ret)
		return (EUTERM);
	
	int col = tgetnum("co");
	int	row = tgetnum("li");
	
	int x = 0;
	int y = 0;
	ret = ft_getcursor_position(&x, &y);
	//printf("x = %d y = %d\n", x, y);
	if (x == 1 && y == 2)
	{
		g_shell.x = 1;
		g_shell.y = 1;
	}
	x = g_shell.x;
	y = g_shell.y;

	//printf("x = %d y = %d\n", x, y);
	right = tgetstr("cm", 0);
	x += offset % col - 1;
	y += offset / col - 1 + g_shell.issignal;
	//y += offset / col - 2;
	//printf("x = %d y = %d\n row = %d col = %d", x, y, row, col);
	if (y >= row - 1)
		y = row - 2;
	right = tgoto(right, x, y);
	write(STDOUT_FILENO, right, ft_strlen(right));
	return (0);
}
