/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:18:25 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/26 17:37:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_load_history(int fd)
{
	char		buffer[BUFSIZE];
	t_history	node;

	while (ret > 0)
	{
		ret = read(fd, buffer, BUFSIZE);
		if (ret < 0)
			ft_manage_error();
		end = ft_get_endline(buffer);
		if (end == BUFSIZE)
			line = ft_strnjoin(line, buffer, BUFSIZE);
		if (!line)
			ft_manage_error();
		
	}
}
