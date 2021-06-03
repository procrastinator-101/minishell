/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error_msg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:59:48 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 19:22:20 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_parser/ft_parser.h"

void	ft_display_error_msg(int error)
{
	int	major;
	int	minor;

	minor = error >> 8;
	major = error & 0xff;
	if (major == ECCO || major == ENCQ)
	{
		ft_putstr_fd("syntax error near unexpected token ", STDERR_FILENO);
		if (major == ENCQ || minor == NEW_LINE)
			ft_putendl_fd("`newline'", STDERR_FILENO);
		else if (minor == SEMICOLON)
			ft_putendl_fd("`;'", STDERR_FILENO);
		else if (minor == PIPE)
			ft_putendl_fd("`|'", STDERR_FILENO);
		else if (minor == DBR_RDC)
			ft_putendl_fd("`>>'", STDERR_FILENO);
		else if (minor == L_RDC)
			ft_putendl_fd("`<'", STDERR_FILENO);
		else if (minor == R_RDC)
			ft_putendl_fd("`>'", STDERR_FILENO);
	}
	else if (major == EMAF)
		ft_putendl_fd("the allocation of some block failed", STDERR_FILENO);
}
