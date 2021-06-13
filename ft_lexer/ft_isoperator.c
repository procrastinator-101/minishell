/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoperator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 12:13:47 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 09:49:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_isoperator(t_token *token)
{
	if (ft_iscntrl_operator(token))
		return (1);
	return (ft_isrdc_operator(token));
}
