/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isword.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:48:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 18:20:43 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_isword(t_token *token)
{
	if (token->type == WORD)
		return (1);
	if (token->type == RDC_LOPERAND || token->type == RDC_ROPERAND)
		return (1);
	return (0);
}
