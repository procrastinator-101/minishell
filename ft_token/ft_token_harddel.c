/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_harddel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:59:48 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 17:48:33 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

void	ft_token_harddel(t_token **node)
{
	if (!node)
		return ;
	free((*node)->str);
	free((*node)->quotes);
	free(*node);
	*node = 0;
}
