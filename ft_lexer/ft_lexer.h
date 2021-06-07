/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:49:23 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 13:53:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "../ft_error/ft_error.h"

# include "../libft/libft.h"
# include "../ft_envp/ft_envp.h"
# include "../ft_token/ft_token.h"
# include "../ft_support_functions/ft_support_functions.h"

# define SINGLE_QUOTED		's'
# define DOUBLE_QUOTED		'd'
# define ESCAPED			'e'
# define UNQUOTED			'u'

# define DELIM_SIZE			9

typedef struct s_shell
{
	char			*ifs;
	t_envp			*envp;
	char			**argv;
	char			**delimiters;
	char			*rdc_operand;
	int				scmd_status;
	int				pipeline_status;
}					t_shell;

t_token				*ft_lexer(char *line, int size, int *error);

int					ft_isquote(char c);
int					ft_isblank(t_token *token);
int					ft_isoperator(t_token *token);
int					ft_isredirection(t_token *token);
int					ft_isrdc_operand(t_token *token);
int					ft_iscntrl_operator(t_token *token);

int					ft_isname(char *name);
int					ft_isactive(char c, char quote);

char				*ft_get_name(char *str, int *error);

char				**ft_get_delimiters(void);
int					ft_find_delimiter(char *str, char **delimiters);

char				*ft_process_quotes(char *line, int size, int *error);
int					ft_process_backslash(char *line, char *quotes, int index);
int					ft_process_double_quotes(char *line, char *quotes, \
					int index);
int					ft_process_single_quotes(char *line, char *quotes, \
					int index);
int					ft_process_cstyle_quoting(char *line, char *quotes, \
					int index);

t_token				*ft_tokenise(char *line, char *quotes, char **delimiters, \
					int *error);
t_token				*ft_strtok(char *line, char *quotes, char **delimiters, \
					int *offset);
int					ft_check_syntax(t_token *tokens);
void				ft_identify_rdc_operands(t_token **tokens);

extern t_shell		g_shell;

#endif
