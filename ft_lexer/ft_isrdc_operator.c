/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrdc_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 08:52:25 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/03 19:09:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_isrdc_operator(t_token *token)
{
	if (token->type == DBR_RDC)
		return (1);
	if (token->type == DBL_RDC)
		return (1);
	if (token->type == L_RDC)
		return (1);
	if (token->type == R_RDC)
		return (1);
	return (0);
}
