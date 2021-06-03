/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:03:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/01 09:30:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_shell g_shell;

int main(void)
{
	int			ret;
	int			error;
	char		*buffer;

	ft_initialise_shell();
	buffer = malloc(1024 * sizeof(char));
	if (!buffer)
		ft_manage_parsing_error(EMAF);
	while (1)
	{
		ret = read(0, buffer, 1023);
		if (ret < 1)
			break ;
		buffer[ret - 1] = 0;
		error = ft_parser(buffer, ret);
		if (error == EMAF)
		{
			free(buffer);
			ft_manage_parsing_error(error);
		}
		else if (error)
			ft_display_error_msg(error);
	}
	free(buffer);
	ft_cleanup();
	return (0);
}
