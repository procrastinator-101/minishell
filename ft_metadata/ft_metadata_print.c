/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metadata_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 11:12:36 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 11:17:09 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_metadata.h"

void	ft_metadata_print(t_metadata *meda)
{
	int	i;

	i = -1;
	while (meda[++i].holder != EOMD)
	{
		if (meda[i].uq)
			printf("%c", 'u');
		else if (meda[i].sq)
			printf("%c", 's');
		else if (meda[i].dq)
			printf("%c", 'd');
		else if (meda[i].es)
			printf("%c", 'e');
	}
	printf("\n");
	i = -1;
	while (meda[++i].holder != EOMD)
		printf("%d", meda[i].va);
	printf("\n");
	i = -1;
	while (meda[++i].holder != EOMD)
		printf("%d", meda[i].ex);
	printf("\n");
}
