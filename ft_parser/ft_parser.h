/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:17:54 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/01 08:45:04 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

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

# include "../ft_error/ft_error.h"
# include "../ft_lexer/ft_lexer.h"

# include "../libft/libft.h"
# include "../ft_envp/ft_envp.h"
# include "../ft_scmd/ft_scmd.h"
# include "../ft_token/ft_token.h"
# include "../ft_pipeline/ft_pipeline.h"
# include "../ft_support_functions/ft_support_functions.h"

#define ESC					27

void		ft_cleanup(void);
void		ft_initialise_shell(void);

int			ft_parser(char *line, int size);

t_scmd		*ft_tokens_to_scmd(t_token **head, int *error);
t_pipeline	*ft_get_cmd_tree(t_token *tokens, int *error);
t_pipeline	*ft_tokens_to_pipeline(t_token **tail, int *error);

#endif
