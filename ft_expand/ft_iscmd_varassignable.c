/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscmd_varassignable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 18:43:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 18:50:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_iscmd_varassignable(t_token *token)
{
	if (!token)
		return (0);
	if (!ft_strcmp(token->str, "alias") || !ft_strcmp(token->str, "declare"))
		return (1);
	if (!ft_strcmp(token->str, "typeset") || !ft_strcmp(token->str, "export"))
		return (1);
	if (!ft_strcmp(token->str, "readonly") || !ft_strcmp(token->str, "local"))
		return (1);
	return (0);
}
