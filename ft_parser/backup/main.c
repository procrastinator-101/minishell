/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:43:28 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/25 11:13:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	main()
{
	int 		index;
	int			error;
	char		termcap[3];
	char		*line;
	char		*line_size;
	char		buffer[BUFFER_SIZE];
	t_termios	std_tty;

	tcgetattr(STDIN_FILENO, &std_tty);
	ft_alter_current_tty(STDIN_FILENO, std_tty);
	line = NULL;
	index = 0;
	line_size = 0;
	//ft_load_history();
	while (1)
	{
		if (index == BUFFER_SIZE)
		{
			index = 0;
			line = ft_strnjoin(line, &line_size, buffer, BUFSIZE);
		}
		error = read(0, buffer + index, 1);
		if (error < 0)
			ft_manage_execution_error(line, error);
		if (line[index] == ESC)
		{
			index--;
			error = ft_handle_termcaps(termcap);
		}
		else if (buffer[index] == '\n')
		{
			line = ft_strnjoin(line, &line_size, buffer, index);
			ft_append_to_history(line, line_size);
			error = ft_execute_line(line);
			if (error)
				ft_manage_execution_error(buffer, line, error);
		}
		index++;
	}
	//restore tty standard settings before exiting
	//update history file before exiting
	return (0);
}
