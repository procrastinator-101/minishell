/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:04:54 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/08 15:59:43 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

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

# include <term.h>
# include <curses.h>

# include "../ft_error/ft_error.h"
# include "../ft_lexer/ft_lexer.h"

# include <readline/history.h>
# include <readline/readline.h>

# include "../libft/libft.h"
# include "../ft_envp/ft_envp.h"
# include "../ft_scmd/ft_scmd.h"
# include "../ft_token/ft_token.h"
# include "../ft_expand/ft_expand.h"
# include "../ft_pipeline/ft_pipeline.h"
# include "../ft_support_functions/ft_support_functions.h"
# include "../execution/execution.h"

void		ft_cleanup(void);
void		ft_terminate(void);
void		ft_initialise_shell(char **argv, char **sys_envp);

void		ft_install_child_signal_handlers(void);
void		ft_install_parent_signal_handlers(void);

int			ft_parser(char *line, int size);
int			ft_pipeline_finalise(t_pipeline *pipeline);

int			ft_scmd_getargs(t_scmd *scmd);
int			ft_scmd_finalise(t_scmd *scmd);
int			ft_pipeline_getargs(t_pipeline *pipeline);

int			ft_scmd_extract_redirections(t_scmd *scmd);
int			ft_pipeline_extract_redirections(t_pipeline *pipeline);

t_scmd		*ft_tokens_to_scmd(t_token **head, int *error);
t_pipeline	*ft_get_cmd_tree(t_token *tokens, int *error);
t_pipeline	*ft_tokens_to_pipeline(t_token **tail, int *error);

char		*ft_handle_hex_escape_sequence(char *cstring, int *len);
char		*ft_handle_octal_escape_sequence(char *cstring, int *len);
char		*ft_handle_control_escape_sequence(char *cstring, int *len);

char		*ft_substitute_parameter(char *str, char quote, int *error, \
			int *len);

char		*ft_get_uniquotes(int size, char type);
char		*ft_remove_quoted_null_arguments(char *src, int *error);

#endif
