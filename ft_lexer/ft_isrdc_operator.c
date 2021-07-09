/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isrdc_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 08:52:25 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 10:51:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_isrdc_operator(t_token *token)
{
	if (token->type == ARO_RDC)
		return (1);
	if (token->type == HDOC_RDC)
		return (1);
	if (token->type == RI_RDC)
		return (1);
	if (token->type == RO_RDC)
		return (1);
	return (0);
}
