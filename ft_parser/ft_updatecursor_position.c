/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_updatecursor_position.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:05:15 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 12:29:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_updatecursor_position(void)
{
	int	fd1;
	int	fd2;

	fd1 = dup(STDIN_FILENO);
	fd2 = dup(STDOUT_FILENO);
	dup2(g_shell.def_in, STDIN_FILENO);
	dup2(g_shell.def_out, STDOUT_FILENO);
	ft_getcursor_position(&(g_shell.x), &(g_shell.y));
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
}
