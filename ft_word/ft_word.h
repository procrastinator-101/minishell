/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:38:17 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 14:42:48 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WORD_H
# define FT_WORD_H

typedef struct s_word
{
	char			*str;
	struct s_word	*next;
	int				type;
}					t_word;

t_word	*ft_word_create(char	*str, int type);

void	ft_word_addback(t_word **tail, t_word *node);
void	ft_word_addfront(t_word **tail, t_word *node);
void	ft_word_del(t_word *node);
void	ft_word_clear(t_word **tail);

#endif
