/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:31:02 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 16:42:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_cleanup(void)
{
	free(g_shell.delimiters);
	ft_envp_clear(&(g_shell.envp));
	close(g_shell.def_in);
	close(g_shell.def_out);
	free(g_shell.terminal);
	free(g_shell.pwd);
}
