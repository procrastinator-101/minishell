/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:24:37 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/01 17:24:56 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	def_in_out(void)
{
	g_shell.def_in = dup(STDIN_FILENO);
	g_shell.def_out = dup(STDOUT_FILENO);
}

void	reset_in_out(void)
{
	dup2(g_shell.def_in, STDIN_FILENO);
	dup2(g_shell.def_out, STDOUT_FILENO);
}
