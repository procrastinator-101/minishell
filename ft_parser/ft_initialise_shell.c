/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_shell.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:56:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 19:23:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_initialise_shell(void)
{
	g_shell.delimiters = ft_get_delimiters();
	if (!g_shell.delimiters)
	{
		ft_display_error_msg(EMAF);
		exit(EXIT_FAILURE);
	}
}
