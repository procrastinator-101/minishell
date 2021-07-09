/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settermios_attr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:59:19 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 13:23:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_settermios_attr(void)
{
	struct termios	tty;

	tcgetattr(STDIN_FILENO, &tty);
	tty.c_lflag &= ~ECHOCTL;
}
