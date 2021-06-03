/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_termios_local_flags.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:27:15 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/26 13:06:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	ft_echo_related_flags(tcflag_t lflag)
{
	if (lflag & ECHOKE)
		printf("visual erase for line kill\n");
	if (lflag & ECHOE)
		printf("visually erase chars\n");
	if (lflag & ECHOK)
		printf("echo NL after line kill\n");
	if (lflag & ECHO)
		printf("enable echoing\n");
	if (lflag & ECHONL)
		printf("echo NL even if ECHO is off\n");
	if (lflag & ECHOPRT)
		printf("visual erase mode for hardcopy\n");
	if (lflag & ECHOCTL)
		printf("echo control chars as ^(Char)\n");
}

void	ft_display_termios_local_flags(tcflag_t lflag)
{
	ft_echo_related_flags(lflag);
	if (lflag & ISIG)
		printf("enable signals INTR, QUIT, [D]SUSP\n");
	if (lflag & ICANON)
		printf("canonicalize input lines\n");
	if (lflag & ALTWERASE)
		printf("use alternate WERASE algorithm\n");
	if (lflag & IEXTEN)
		printf("enable DISCARD and LNEXT\n");
	if (lflag & EXTPROC)
		printf("external processing\n");
	if (lflag & TOSTOP)
		printf("stop background jobs from output\n");
	if (lflag & FLUSHO)
		printf("output being flushed (state)\n");
	if (lflag & NOKERNINFO)
		printf("no kernel output from VSTATUS\n");
	if (lflag & PENDIN)
		printf("XXX retype pending input (state)\n");
	if (lflag & NOFLSH)
		printf("don't flush after interrupt\n");
}
