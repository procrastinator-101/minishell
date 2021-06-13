/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:49:23 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 18:42:45 by yarroubi         ###   ########.fr       */
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

int					ft_isrdc_operator(t_token *token);
int					ft_isoperator(t_token *token);
int					ft_iscntrl_operator(t_token *token);

int					ft_isquote(char c);
int					ft_isquoted(char c, t_metadata meda);

int					ft_isword(t_token *token);
int					ft_isblank(t_token *token);
int					ft_isrdc_operand(t_token *token);

int					ft_isname(char *name);
char				*ft_get_name(char *str, int *error);

void				ft_identify_rdc_operands(t_token **tokens);

char				**ft_get_delimiters(void);
int					ft_find_delimiter(char *str, char **delimiters);

int					ft_check_syntax(t_token *tokens);
t_token				*ft_lexer(char *line, int size, int *error);

t_metadata			*ft_process_quotes(char *str, int size, int *error);
int					ft_process_single_quotes(char *str, t_metadata *meda, \
					int index);
int					ft_process_double_quotes(char *str, t_metadata *meda, \
					int index);
int					ft_process_cstyle_quoting(char *str, t_metadata *meda, \
					int index);
int					ft_process_backslash(char *str, t_metadata *meda, \
					int index);

t_token				*ft_tokenise(char *str, t_metadata *meda, char **delimiters, \
					int *error);
t_token				*ft_strtok(char *str, t_metadata *meda, char **delimiters, \
					int *offset);

extern t_shell		g_shell;

#endif
