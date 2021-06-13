/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rquotes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:02:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 18:14:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int main()
{
	int		ret;
	int		error;
	char	*dst;
	char	*src;

	while (ret > 0)
	{
		src = malloc(1024 * sizeof(char));
		ret = read(0, src, 1023);
		if (ret < 0)
			return (0);
		src[ret] = 0;
		dst = ft_remove_quoted_null_arguments(src, &error);
		printf("{%s}\n", dst);
		free(dst);
	}
	return (0);
}
