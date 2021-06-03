/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:21:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/01 10:28:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_token	*ft_expand(t_token *token, int *error)
{
	ret = ft_parameter_expansion(&token, error);
	if (*error)
		return (0);
	if (ret)
		token = ft_word_spliting(token, error);
	return (ft_quotes_removal(token, error));
}
