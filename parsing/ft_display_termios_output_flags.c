/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_termios_output_flags.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:54:21 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/26 13:06:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_display_termios_output_flags(unsigned long oflag)
{
	if (oflag & OPOST)
		printf("enable following output processing\n");
	if (oflag & ONLCR)
		printf("map NL to CR-NL (ala CRMOD)\n");
	if (oflag & OXTABS)
		printf("expand tabs to spaces\n");
	if (oflag & ONOEOT)
		printf("discard EOT's (^D) on output\n");
}
