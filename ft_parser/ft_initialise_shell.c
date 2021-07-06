/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_shell.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:56:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/05 16:13:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_initialise_shell(char **argv, char **sys_envp)
{
	int	error;

	g_shell.delimiters = ft_get_delimiters();
	if (!g_shell.delimiters)
	{
		ft_display_error_msg(EMAF);
		exit(EXIT_FAILURE);
	}
	g_shell.envp = ft_load_sys_envp(sys_envp, &error);
	if (error)
	{
		ft_display_error_msg(error);
		free(g_shell.delimiters);
		exit(EXIT_FAILURE);
	}
	g_shell.argv = argv;
	g_shell.ifs = "\t \n";
	g_shell.prompt = "Minishell% ";
	g_shell.rdc_operand = 0;
}
