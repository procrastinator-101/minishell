/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcursor_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:15:45 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 15:33:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static int	ft_read_position(char *buffer)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < 30)
	{
		ret = read(STDIN_FILENO, buffer + i, 1);
		if (ret < 1)
			break ;
		if (buffer[i] == 'R')
			break ;
	}
	if (buffer[i] == 'R')
		return (0);
	return (1);
}

static int	ft_fetchcursor_position(int *x, int *y)
{
	int				ret;
	char			buffer[30];
	struct termios	std;
	struct termios	usr;

	tcgetattr(STDIN_FILENO, &std);
	usr = std;
	usr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &usr);
	write(STDIN_FILENO, "\033[6n", 4);
	ret = ft_read_position(buffer);
	tcsetattr(STDIN_FILENO, TCSANOW, &std);
	if (ret)
		return (ret);
	*y = ft_atoi_length(buffer + 2, &ret);
	*x = ft_atoi_length(buffer + ret + 3, &ret);
	return (0);
}

int	ft_getcursor_position(int *x, int *y)
{
	int	fd1;
	int	fd2;
	int	ret;

	fd1 = dup(STDIN_FILENO);
	fd2 = dup(STDOUT_FILENO);
	dup2(g_shell.def_in, STDIN_FILENO);
	dup2(g_shell.def_out, STDOUT_FILENO);
	if (!isatty(STDIN_FILENO))
		return (-1);
	ret = ft_fetchcursor_position(x, y);
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	if (ret)
		return (ret);
	return (0);
}
