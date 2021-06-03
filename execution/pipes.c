/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:41:14 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/03 11:04:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void	handle_signal(int signal)
{
	printf("error = %d\n", 2);
	exit(1);
}

int main()
{
	int	fd[2];

	pipe(fd);
	close(fd[0]);
	signal(SIGPIPE, handle_signal);
	write(fd[1], "msg1", 5);

	printf("fd0 = %d fd1 = %d\n", fd[0], fd[1]);
	int ret = 1;
	while (ret > 0)
	{
		char buffer[100];
		ret = read(fd[0], buffer, 100);
		printf("ret = %d\n", ret);
		printf("buff = %s\n", buffer);
	}
	close(fd[0]);
}
