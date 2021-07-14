/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:59:25 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 14:52:10 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_terminate(void)
{
	ft_resetcursor_position(ft_strlen("Minishell% "));
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	ft_cleanup();
	ft_resettermios_attr();
	exit(g_shell.pipeline_status);
}
