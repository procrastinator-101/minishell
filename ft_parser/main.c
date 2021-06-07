/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:03:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/05 16:38:11 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_shell g_shell;

int main(int argc, char **argv, char **sys_envp)
{
	int			ret;
	int			error;
	char		*str;
	char		*buffer;

	if (argc > 1)
		ft_manage_parsing_error(0);
	ft_initialise_shell(argv, sys_envp);
	buffer = malloc(1024 * sizeof(char));
	if (!buffer)
		ft_manage_parsing_error(EMAF);
	str = 0;
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
