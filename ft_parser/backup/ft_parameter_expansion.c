/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_expansion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:29:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 19:54:14 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_parameter_expansion(t_token **src, int *error)
{
	int		i;
	int		ret;
	char	*str;
	char	*quotes;
	t_token	*dst;

	i = 0;
	ret = 0;
	dst = 0;
	while ((*src)->str[i])
	{
		if ((*src)->str[i] == '$')
		{
			if ((*src)->quotes[i] == UNQUOTED)
				i += ft_dqparameter_expansion(str + i, &ptr, &quotes, error);
			else if ((*src)->quotes[i] == DOUBLE_QUOTED)
				i += ft_ndqparameter_expansion(str + i, &ptr, &quotes, error);
			else
				continue ;
			ret = 1;
			if (*error)
			{
				ft_token_del(dst);
				return (1);
			}
			ft_update_dst(&dst, ptr, quotes);
			if (*error)
				return (1);
		}
		else
			i++;
	}
	return (ret);
}
