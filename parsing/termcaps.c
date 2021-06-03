/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 15:45:30 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/18 14:53:46 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(void)
{
	int		ret;
	char	*buffer;

	ret = tgetent(0, "xterm-256color");
	if (ret < 1)
		exit(EXIT_FAILURE);
	buffer = malloc(100 * sizeof(char));
	ret = 1;
	
	/*
	while (ret > 0)
	{
		ret = read(0, buffer, 100);
		printf("ret = %d\n", ret);
		for (int i = 0; i < ret; i++)
			printf("is a termcap = %d\n", buffer[i]);
		printf("buffer = %s\n", buffer);
	}
	*/
	
	printf("is a termcap = %d\n", tgetflag("li"));
	printf("is a termcap = %d\n", tgetnum("li"));
	char	*termcap = tgetstr("cm", 0);
	printf("%s\n", tgoto(termcap, 15, 35));
	printf("is a termcap = %d\n", tgetnum("li"));
	
	return (0);
}
