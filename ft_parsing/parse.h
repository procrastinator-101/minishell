/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:27:28 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/26 13:08:09 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H


# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# include <errno.h>

# include <ctype.h>
# include <signal.h>
# include <unistd.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/types.h>

#include <term.h>
#include <curses.h>

/*
**	these are for testing only ************************************************
*/

#include <grp.h>
#include <pwd.h>
#include <time.h>

typedef struct stat	t_stat;

int		ft_stat(char *file_name);

void	ft_display_termios_local_flags(tcflag_t lflag);
void	ft_display_termios_control_flags(tcflag_t cflag);
void	ft_display_termios_input_flags(unsigned long iflag);
void	ft_display_termios_output_flags(unsigned long oflag);

/*
**	end ***********************************************************************
*/

#endif
