/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 14:29:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/07 17:27:38 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(void)
{
	/*
	int fd = open("/dev/ttys004", O_RDONLY);
	printf("fd = %d\n", fd);
	for (int i = 0; i < 4; i++)
	{
		printf("fd = %d\t", i);
		printf("isatty = %d\t", isatty(i));
		printf("ttyname = %s\n", ttyname(i));
	}
	char buffer[1024];

	char str[] = "msg 1";
	write(fd, str, strlen(str));
	while (1)
	{
		int len = read(0, buffer, 1024);
		printf("ret = %lu\n", write(fd, buffer, len));
		printf("buffer = %s\n", buffer);
	}
	*/
	printf("index = %d\n", ttyslot());
	return (0);
}
