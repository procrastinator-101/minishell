/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:09:51 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 15:00:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# define DBR_RDC			1
# define SEMICOLON			2
# define PIPE				3
# define NEW_LINE			4
# define L_RDC				5
# define R_RDC				6
# define SPACE				7
# define TAB				8
# define WORD				9
# define RDC_ROPERAND		10
# define RDC_LOPERAND		11
# define ENDL				12

# include <stdio.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef struct s_token
{
	char			*str;
	char			*quotes;
	struct s_token	*next;
	char			type;
}					t_token;

int					ft_token_size(t_token *tail);
void				ft_token_del(t_token *node);
void				ft_token_print(t_token *node);
void				ft_token_print_type(int type);
void				ft_token_harddel(t_token **node);
void				ft_token_clear(t_token **tail);
void				ft_token_addback(t_token **tail, t_token *node);
t_token				*ft_token_create(char *line, char *quotes, int size, \
					int type);

#endif
