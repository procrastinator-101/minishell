/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 10:44:47 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/30 10:45:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_iscntrl_operator(t_token *token)
{
	if (token->type == SEMICOLON)
		return (1);
	if (token->type == PIPE)
		return (1);
	if (token->type == NEW_LINE)
		return (1);
	return (0);
}
