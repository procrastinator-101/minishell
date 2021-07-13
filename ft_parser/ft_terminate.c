/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:59:25 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 18:48:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_terminate(void)
{
	ft_resetcursor_position(ft_strlen("Minishell% "));
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	close(g_shell.def_in);
	close(g_shell.def_out);
	ft_cleanup();
	exit(EXIT_SUCCESS);
}
