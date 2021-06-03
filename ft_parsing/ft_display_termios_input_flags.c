/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_termios_input_flags.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:21:35 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/26 12:38:47 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	ft_parity_related_flags(unsigned long iflag)
{
	if (iflag & IGNPAR)
		printf("ignore (discard) parity errors\n");
	if (iflag & PARMRK)
		printf("mark parity and framing errors\n");
	if (iflag & INPCK)
		printf("enable checking of parity errors\n");
}

void	ft_display_termios_input_flags(unsigned long iflag)
{
	ft_parity_related_flags(iflag);
	if (iflag & IGNBRK)
		printf("ignore BREAK condition\n");
	if (iflag & BRKINT)
		printf("map BREAK to SIGINTR\n");
	if (iflag & ISTRIP)
		printf("strip 8th bit off chars\n");
	if (iflag & INLCR)
		printf("map NL into CR\n");
	if (iflag & IGNCR)
		printf("ignore CR\n");
	if (iflag & ICRNL)
		printf("map CR to NL (ala CRMOD)\n");
	if (iflag & IXON)
		printf("enable output flow control\n");
	if (iflag & IXOFF)
		printf("enable input flow control\n");
	if (iflag & IXANY)
		printf("any char will restart after stop\n");
	if (iflag & IMAXBEL)
		printf("ring bell on input queue full\n");
	if (iflag & IUTF8)
		printf("maintain state for UTF-8 VERASE\n");
}
