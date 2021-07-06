/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_install_signal_handlers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:22:11 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/06 11:34:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void ft_handle_signal(int signal)
{
	if (signal)
	{
		rl_replace_line(g_shell.prompt, 0);
		rl_on_new_line();
	}
	//write(1, "h\n", 2);
}

void	ft_install_signal_handlers(void)
{
	signal(SIGINT, ft_handle_signal);
	signal(SIGQUIT, SIG_IGN);
}
