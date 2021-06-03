/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alter_current_tty.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:23:51 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 16:37:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_alter_current_tty(int fd, t_termios std_tty)
{
	std_tty.c_lflag &= ~ISIG;
	std_tty.c_lflag &= ~ICANON;
	tcsetattr(fd, TCSANOW, &std_tty);
}
