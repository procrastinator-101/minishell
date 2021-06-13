/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:44:55 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 18:51:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPAND_H
# define FT_EXPAND_H

# include "../ft_error/ft_error.h"
# include "../ft_lexer/ft_lexer.h"

# include "../libft/libft.h"
# include "../ft_envp/ft_envp.h"
# include "../ft_token/ft_token.h"
# include "../ft_pipeline/ft_pipeline.h"
# include "../ft_support_functions/ft_support_functions.h"

int		ft_expand_scmd(t_scmd *scmd);
int		ft_expand_pipeline(t_pipeline *pipeline);
t_token	*ft_expand_token(t_token *token, int *error);

int		ft_parameter_expansion(t_token *token);
int		ft_manage_active_expansion(t_token *token, char *str, \
		t_metadata *meda);
int		ft_manage_passive_expansion(t_token *token, char *str, \
		t_metadata *meda);

t_token	*ft_quote_removal(t_token *token);
t_token	*ft_word_spliting(t_token *token, int *error);

int		ft_iscmd_varassignable(t_token *token);
void	ft_identify_variable_assignments(t_token *tokens);

int		ft_isifs(char c);
int		ft_is_special_parameter(char c);
int		ft_isparameter_expandable(t_token *token);
int		ft_traverse_ifs(char *str, t_metadata *meda);

int		ft_append_normal_sequence(char **str, char *cstring);
int		ft_append_escape_sequence(char **str, char *cstring);
char	*ft_handle_hex_escape_sequence(char *cstring, int *len);
char	*ft_expand_cstring(char *str, t_metadata *meda, int *len);
char	*ft_handle_octal_escape_sequence(char *cstring, int *len);
char	*ft_handle_control_escape_sequence(char *cstring, int *len);
char	*ft_handle_character_escape_sequence(char *cstring, int *len);

char	*ft_substitute_parameter(char *str, char quote, int *error, int *len);

int		ft_expand_asyntactic_names(t_token *token, char *str, t_metadata *meda);
int		ft_expand_normal_construct(t_token *token, char *str, t_metadata *meda);
int		ft_expand_special_parameters(t_token *token, char *str, \
		t_metadata *meda);
int		ft_expand_singlequote_construct(t_token *token, char *str, \
		t_metadata *meda);

#endif
