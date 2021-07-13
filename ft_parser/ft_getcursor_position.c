/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcursor_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:15:45 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 11:10:23 by yarroubi         ###   ########.fr       */
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

int	ft_getcursor_position(int *x, int *y)
{
	int				ret;
	char			buffer[30];
	struct termios	std;
	struct termios	usr;

	if (!isatty(STDIN_FILENO))
		return (-1);
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
