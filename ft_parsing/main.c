/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 10:43:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/29 13:44:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

struct termios std_tty;
int fd;

void	ft_handle_signals(int signal)
{
	tcsetattr(fd, TCSANOW, &std_tty);
	printf("well, let's leave\n");
	exit(EXIT_FAILURE);
}

int	ft_handle_special_control_characters(char c, cc_t c_cc[NCCS])
{
	int	i;
	int	ret;

	i = -1;
	while (++i < NCCS)
	{
		if (c == c_cc[VINTR])
			ret = kill(getpid(), SIGINT);
		else if (c == c_cc[VQUIT])
			ret = kill(getpid(), SIGQUIT);
		if (ret == -1)
			printf("killing the current process failed\n");
	}
	return (0);
}

int	main(void)
{
	struct termios my_tty;

   
	fd = STDIN_FILENO;
	tcgetattr(fd, &std_tty);

	my_tty = std_tty;

	//my_tty.c_lflag &= ~ICANON;
	//my_tty.c_lflag &= ~ECHO;
	//my_tty.c_lflag &= ~ISIG;
	my_tty.c_lflag |= IEXTEN;
	//my_tty.c_lflag |= ALTWERASE;
	
	signal(SIGINT, ft_handle_signals);
	signal(SIGTTOU, ft_handle_signals);
	signal(SIGQUIT, ft_handle_signals);
	tcsetattr(fd, TCSANOW, &my_tty);
	printf("ttyname = %s\n", ttyname(fd));

	printf("\n==================== std_tty lflag ====================\n");
	ft_display_termios_local_flags(std_tty.c_lflag);
	printf("=======================================================\n");
	printf("\n==================== my_tty lflag ====================\n");
	ft_display_termios_local_flags(my_tty.c_lflag);
	printf("=======================================================\n");
	printf("iflag = %lu\n", std_tty.c_ispeed);
	printf("iflag = %lu\n", std_tty.c_ospeed);
	/*
	for (int i = 0; i < NCCS; i++)
		printf("%d\t", std_tty.c_cc[i]);
	printf("\n");
	for (int i = 0; i < NCCS; i++)
		printf("%d\t", i);
	*/
	printf("\n");
	char buffer[1024];
	int ret = 1;
	while (ret > 0)
	{
		ret = read(0, buffer, 1024);
		write(1, std_tty.c_cc + VDISCARD, 1);
		if (ret > 0)
			write(1, buffer, ret);
		for (int i = 0; i < ret; i++)
			ft_handle_special_control_characters(buffer[i], my_tty.c_cc);
	}
	tcsetattr(fd, TCSANOW, &std_tty);

	return (0);
}
