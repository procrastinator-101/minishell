/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrdc_operand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:18:42 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 17:29:58 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_isrdc_operand(t_token *token)
{
	if (token->type == RDC_ROPERAND || token->type == RDC_LOPERAND)
		return (1);
	return (0);
}
