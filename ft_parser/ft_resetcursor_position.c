/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetcursor_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:20:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 11:25:51 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_resetcursor_position(int offset)
{
	int		ret;
	char	*right;

	//has to be protected 
	int col = tgetnum("co");
	int	row = tgetnum("li");
	
	int x = 0;
	int y = 0;
	ret = ft_getcursor_position(&x, &y);
	//printf("x = %d y = %d\n", x, y);
	if (x == 1 && y == 2)
	{
		g_shell.x = 1;
		g_shell.y = 0;
	}
	x = g_shell.x;
	y = g_shell.y;
	//printf("x = %d y = %d\n", x, y);

	//printf("x = %d y = %d\n", x, y);
	right = tgetstr("cm", 0);
	/*
	x += offset % col - 1;
	y += offset / col - 1 + g_shell.issignal;
	*/
	int tmp = x;
	x = (x + offset) % col - 1;
	y += (tmp + offset) / col - 1 + g_shell.issignal;
	//printf("x = %d y = %d\n row = %d col = %d", x, y, row, col);
	if (y >= row - 1)
		y = row - 2;
	if (x < 1)
		x = 1;
	if (y < 0)
		y = 0;
	//printf("y = %d x = %d\n row = %d col = %d", y, x, row, col);
	//printf("x = %d y = %d\n", x, y);

	right = tgoto(right, x, y);
	write(STDOUT_FILENO, right, ft_strlen(right));
	return (0);
}
