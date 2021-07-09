/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrdc_operand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:18:42 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 10:51:22 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_isrdc_operand(t_token *token)
{
	if (token->type == RI_ROPERAND || token->type == RO_ROPERAND)
		return (1);
	if (token->type == ARO_ROPERAND || token->type == HDOC_ROPERAND)
		return (1);
	return (0);
}
