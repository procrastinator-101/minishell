/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isredirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:12:00 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/29 12:13:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_isredirection(t_token *token)
{
	if (token->type == DBR_RDC)
		return (1);
	if (token->type == L_RDC)
		return (1);
	if (token->type == R_RDC)
		return (1);
	return (0);
}
