/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:09:19 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 15:30:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REDIRECTION_H
# define FT_REDIRECTION_H

# include "../libft/libft.h"
# include "../ft_token/ft_token.h"
# include "../ft_support_functions/ft_support_functions.h"

typedef struct s_redirection
{
	char					*left_operand;
	char					*right_operand;
	struct s_redirection	*next;
	int						type;
}							t_redirection;

void						ft_redirection_del(t_redirection *node);
void						ft_redirection_print(t_redirection *tail);
void						ft_redirection_clear(t_redirection **tail);
void						ft_redirection_addback(t_redirection **tail, \
							t_redirection *node);
t_redirection				*ft_redirection_create(char *left, char *right, \
							int type);
#endif
