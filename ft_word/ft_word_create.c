/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:02:54 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 14:06:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_word.h"

t_word	ft_word_create(char *str, int type)
{
	t_word	*word;

	word = malloc(sizeof(t_word));
	if (word)
		return (0);
	word->str = str;
	word->type = type;
	word->node = 0;
	return (word);
}
