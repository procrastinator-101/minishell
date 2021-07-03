/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:15:02 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/03 19:11:11 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static t_metadata	*ft_set_error(t_metadata *meda, int *error, int type)
{
	free(meda);
	*error = type;
	return (0);
}

t_metadata	*ft_process_quotes(char *str, int size, int *error)
{
	int			i;
	t_metadata	*meda;

	meda = ft_metadata_create(size);
	if (!meda)
		return (ft_set_error(meda, error, EMAF));
	i = 0;
	*error = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			i = ft_process_single_quotes(str, meda, i);
		else if (str[i] == '"')
			i = ft_process_double_quotes(str, meda, i);
		else if (str[i] == '$')
			i = ft_process_cstyle_quoting(str, meda, i);
		else
			meda[i++].uq = 1;
		if (i < 0)
			return (ft_set_error(meda, error, -i));
	}
	return (meda);
}
