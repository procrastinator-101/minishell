/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_print_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:56:22 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/03 19:05:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

static void	ft_print_operator(int type)
{
	if (type == DBR_RDC)
		printf("DBR_RDC\n");
	else if (type == DBL_RDC)
		printf("DBL_RDC\n");
	else if (type == SEMICOLON)
		printf("SEMICOLON\n");
	else if (type == PIPE)
		printf("PIPE\n");
	else if (type == L_RDC)
		printf("L_RDC\n");
	else if (type == R_RDC)
		printf("R_RDC\n");
	else if (type == NEW_LINE)
		printf("NEW_LINE\n");
}

void	ft_token_print_type(int type)
{
	if (type == SPACE)
		printf("SPACE\n");
	else if (type == TAB)
		printf("TAB\n");
	else if (type == WORD)
		printf("WORD\n");
	else if (type == RDC_ROPERAND)
		printf("RDC_ROPERAND\n");
	else if (type == RDC_LOPERAND)
		printf("RDC_LOPERAND\n");
	else
		ft_print_operator(type);
}
