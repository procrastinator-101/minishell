/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:28:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 17:10:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCMD_H
# define FT_SCMD_H

# include "../ft_token/ft_token.h"
# include "../ft_redirection/ft_redirection.h"

typedef struct s_scmd
{
	char			**args;
	t_token			*tokens;
	t_redirection	*redirections;
	struct s_scmd	*next;
}					t_scmd;

t_scmd				*ft_scmd_create(t_token *tokens, char **args, \
					t_redirection *rdcs);

void				ft_scmd_del(t_scmd *node);
void				ft_scmd_print(t_scmd *tail);
void				ft_scmd_clear(t_scmd **tail);
void				ft_scmd_addback(t_scmd **tail, t_scmd *node);
void				ft_scmd_addfront(t_scmd **tail, t_scmd *node);

#endif
