/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error_msg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:59:48 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 13:26:29 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parser/ft_parser.h"

static void	ft_display_syntax_error_msg(int major, int minor)
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

static void	ft_display_fatal_error_msg(int major)
{
	if (major == EMAF)
		ft_putendl_fd("the allocation of some block failed", STDERR_FILENO);
	else if (major == EFPF)
		ft_putendl_fd(": forking process failure", STDERR_FILENO);
	else if (major == EOFF)
		ft_putendl_fd(": opening file failure", STDERR_FILENO);
	else if (major == EUTERM)
		ft_putendl_fd(": unrecognised terminal", STDERR_FILENO);
	else if (major == ETERMINFO)
		ft_putendl_fd(": terminal database not found", STDERR_FILENO);
	else if (major == ETCID)
		ft_putendl_fd(": terminal could not be identified", STDERR_FILENO);
	else if (major == ETERCAP)
		ft_putendl_fd(": a termcap related problem occured", STDERR_FILENO);
}

void	ft_display_error_msg(int error)
{
	int	major;
	int	minor;

	minor = error >> 8;
	major = error & 0xff;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (major == EURDC)
	{
		ft_putstr_fd(g_shell.rdc_operand, STDERR_FILENO);
		ft_putendl_fd(": ambiguous redirect", STDERR_FILENO);
	}
	else if (major == ECCO || major == ENCQ)
		ft_display_syntax_error_msg(major, minor);
	else
		ft_display_fatal_error_msg(major);
}
