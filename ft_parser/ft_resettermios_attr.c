/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resettermios_attr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 15:11:06 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 15:11:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_resettermios_attr(void)
{
	struct termios	tty;

	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &tty);
}
