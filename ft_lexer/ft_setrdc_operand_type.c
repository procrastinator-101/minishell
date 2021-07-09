/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setrdc_operand_type.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:43:02 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 10:53:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

void	ft_setrdc_operand_type(t_token *token, int rdc_operator)
{
	if (rdc_operator == ARO_RDC)
		token->type = ARO_ROPERAND;
	else if (rdc_operator == HDOC_RDC)
		token->type = HDOC_ROPERAND;
	else if (rdc_operator == RI_RDC)
		token->type = RI_ROPERAND;
	else
		token->type = RO_ROPERAND;
}
