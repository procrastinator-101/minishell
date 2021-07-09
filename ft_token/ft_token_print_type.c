/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_print_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:56:22 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 11:05:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

static void	ft_print_operator(int type)
{
	if (type == ARO_RDC)
		printf("ARO_RDC\n");
	else if (type == HDOC_RDC)
		printf("HDOC_RDC\n");
	else if (type == PIPE)
		printf("PIPE\n");
	else if (type == RI_RDC)
		printf("RI_RDC\n");
	else if (type == RO_RDC)
		printf("RO_RDC\n");
	else if (type == NEW_LINE)
		printf("NEW_LINE\n");
	else if (type == SEMICOLON)
		printf("SEMICOLON\n");
}

void	ft_token_print_type(int type)
{
	if (type == SPACE)
		printf("SPACE\n");
	else if (type == TAB)
		printf("TAB\n");
	else if (type == WORD)
		printf("WORD\n");
	else if (type == RI_ROPERAND)
		printf("RI_ROPERAND\n");
	else if (type == RO_ROPERAND)
		printf("RO_ROPERAND\n");
	else if (type == ARO_ROPERAND)
		printf("ARO_ROPERAND\n");
	else if (type == HDOC_ROPERAND)
		printf("HDOC_ROPERAND\n");
	else
		ft_print_operator(type);
}
