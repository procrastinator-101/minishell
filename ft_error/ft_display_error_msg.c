/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error_msg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:59:48 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 12:42:10 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parser/ft_parser.h"

void	ft_display_error_msg(int error)
{
	int	major;
	int	minor;

	minor = error >> 8;
	major = error & 0xff;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (major == ECCO || major == ENCQ)
	{
		ft_putstr_fd("syntax error near unexpected token ", STDERR_FILENO);
		if (major == ENCQ || minor == NEW_LINE)
			ft_putendl_fd("`newline'", STDERR_FILENO);
		else if (minor == SEMICOLON)
			ft_putendl_fd("`;'", STDERR_FILENO);
		else if (minor == PIPE)
			ft_putendl_fd("`|'", STDERR_FILENO);
		else if (minor == ARO_RDC)
			ft_putendl_fd("`>>'", STDERR_FILENO);
		else if (minor == HDOC_RDC)
			ft_putendl_fd("`<<'", STDERR_FILENO);
		else if (minor == RI_RDC)
			ft_putendl_fd("`<'", STDERR_FILENO);
		else if (minor == RO_RDC)
			ft_putendl_fd("`>'", STDERR_FILENO);
	}
	else if (major == EURDC)
	{
		ft_putstr_fd(g_shell.rdc_operand, STDERR_FILENO);
		ft_putendl_fd(": ambiguous redirect", STDERR_FILENO);
	}
}
