/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:36:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/04/04 14:40:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	main(void)
{
	int		ret;
	char	*buffer;

	buffer = malloc(100 * sizeof(char));
	ret = 1;
	while (ret > 0)
	{
		ret = read(0, buffer, 100);
		printf("buffer = %s\n", buffer);
	}
	return (0);
}
