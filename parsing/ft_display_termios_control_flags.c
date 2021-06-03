/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_termios_control_flags.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:21:42 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/26 13:07:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	character_size_flags(tcflag_t cflag)
{
	if (cflag & CSIZE)
		printf("character size mask\n");
	if (cflag & CS5)
		printf("5 bits (pseudo)\n");
	if (cflag & CS6)
		printf("6 bits\n");
	if (cflag & CS7)
		printf("7 bits\n");
	if (cflag & CS8)
		printf("8 bits\n");
}

static void	flow_control_flags(tcflag_t cflag)
{
	if (cflag & CCTS_OFLOW)
		printf("CTS flow control of output\n");
	if (cflag & CRTS_IFLOW)
		printf("RTS flow control of input\n");
	if (cflag & CDTR_IFLOW)
		printf("DTR flow control of input\n");
	if (cflag & CDSR_OFLOW)
		printf("DSR flow control of output\n");
	if (cflag & CCAR_OFLOW)
		printf("DCD flow control of output\n");
	if (cflag & MDMBUF)
		printf("old name for CCAR_OFLOW\n");
}

void	ft_display_termios_control_flags(tcflag_t cflag)
{
	if (cflag & CIGNORE)
		printf("ignore control flags\n");
	if (cflag & CSTOPB)
		printf("send 2 stop bits\n");
	if (cflag & CREAD)
		printf("enable receiver\n");
	if (cflag & PARENB)
		printf("parity enable\n");
	if (cflag & PARODD)
		printf("odd parity, else even\n");
	if (cflag & HUPCL)
		printf("hang up on last close\n");
	if (cflag & CLOCAL)
		printf("ignore modem status lines\n");
	character_size_flags(cflag);
	flow_control_flags(cflag);
}
