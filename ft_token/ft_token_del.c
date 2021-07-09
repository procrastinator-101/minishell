/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:03:28 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 11:07:28 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

void	ft_token_del(t_token *node)
{
	if (!node)
		return ;
	free(node->str);
	free(node->meda);
	free(node);
}
