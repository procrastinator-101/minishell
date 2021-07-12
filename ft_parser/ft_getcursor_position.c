/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcursor_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:15:45 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/12 20:53:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_atoi_length(char *str, int *len)
{
	int	i;
	int	sp;
	int	ret;

	*len = 0;
	sp = 0;
	while (str[sp] == 32 || (str[sp] > 8 && str[sp] < 14))
		sp++;
	i = sp;
	if (str[sp] == '-' || str[sp] == '+')
		i++;
	ret = 0;
	while (str[i] > 47 && str[i] < 58)
		ret = ret * 10 + (str[i++] - 48);
	*len = i - sp;
	return (str[sp] == '-' ? -ret : ret);
}

int ft_getcursor_position(int fd)
{
	int				x;
	int				y;
	int				ret;
	int				len;
	char			buffer[100];
	struct termios	std;
	struct termios	usr;

	if (!isatty(fd))
		return (-1);
	tcgetattr(fd, &std);
	usr = std;
	usr.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(0, TCSANOW, &usr);
	write(1, "\033[6n", 4);

	int i = 0;
	bzero(buffer, 100);
	while (buffer[i] != 'R')
	{
		ret = read(fd, buffer + i, 1);
		if (ret < 1)
			break ;
		i++;
	}
	if (buffer[i] == 'R')
	{
		x = ft_atoi_length(buffer, &len);
		y = ft_atoi_length(buffer + len, &len);
	}
	tcsetattr(0, TCSANOW, &std);
	printf("x = %d y = %d\n", x, y);
	return (0);
}

int main()
{
	ft_getcursor_position(STDIN_FILENO);
}
