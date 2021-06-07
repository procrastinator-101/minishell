/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_parsing_error_msg.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:04:40 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 19:06:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_display_parsing_error_msg(int error, char **delimiters)
{
	int	major;
	int	minor;

	minor = error >> 8;
	major = error & 0xff;
	if (major == ECCO || major == ENCQ)
	{
		ft_putstr_fd("syntax error near unexpected token ", STDERR_FILENO);
		if (major == ENCQ)
			ft_putendl_fd("`newline'", STDERR_FILENO);
		else if (minor < DELIM_SIZE && minor != NEW_LINE)
			ft_putendl_fd(delimiters[minor], STDERR_FILENO);
		else
			ft_putendl_fd("`newline'", STDERR_FILENO);
	}
}
