/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetcursor_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:20:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 11:24:38 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_resetcursor_position(int offset)
{
	//int		i;
	int		fd1;
	int		fd2;
	int		ret;
	char	*right;

	if (!offset)
		ret = offset;
	ret = tgetent(NULL, g_shell.terminal);
	if (ret == -1)
		return (ETERMINFO);
	else if (!ret)
		return (EUTERM);
	
	//int col = tgetnum("co");
	
	//right = tgetstr("nd", NULL);
	int x = 0;
	int y = 0;
	fd1 = dup(STDIN_FILENO);
	fd2 = dup(STDOUT_FILENO);
	dup2(g_shell.def_in, STDIN_FILENO);
	dup2(g_shell.def_out, STDOUT_FILENO);
	ret = ft_getcursor_position(&x, &y);
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	right = tgetstr("cm", 0);
	right = tgoto(right, x + offset, y - 2);
	write(STDOUT_FILENO, right, ft_strlen(right));
	//tputs(right, 1, putchar);
	//printf("x = %d y = %d\n", x, y);
	if (ret)
	{
		write(STDERR_FILENO, "error\n", 6);
		return (ret);
	}
	/*
	if (x < col)
	{
		write(STDOUT_FILENO, right, ft_strlen(right));
		write(STDOUT_FILENO, right, ft_strlen(right));
	}
	*/
	return (0);
}
