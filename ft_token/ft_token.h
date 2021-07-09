/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:09:51 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 12:03:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# define ARO_RDC			1
# define HDOC_RDC			2
# define PIPE				3
# define NEW_LINE			4
# define RI_RDC				5
# define RO_RDC				6
# define SPACE				7
# define TAB				8
# define WORD				9
# define RI_ROPERAND		11
# define RO_ROPERAND		12
# define ARO_ROPERAND		13
# define HDOC_ROPERAND		14
# define ENDL				15
# define SEMICOLON			16

# include <stdio.h>
# include <stdlib.h>

# include "../libft/libft.h"
# include "../ft_metadata/ft_metadata.h"

typedef struct s_token
{
	char			*str;
	t_metadata		*meda;
	struct s_token	*next;
	char			type;
	char			hasquotes;
}					t_token;

int					ft_token_size(t_token *tail);
void				ft_token_del(t_token *node);
void				ft_token_print(t_token *node);
void				ft_token_print_type(int type);
void				ft_token_harddel(t_token **node);
void				ft_token_clear(t_token **tail);
void				ft_token_addback(t_token **tail, t_token *node);
t_token				*ft_token_create(char *line, t_metadata *meda, int size, \
					int type);

#endif
