/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:11:17 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/29 10:13:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int main(int argc, char **argv)
{
	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
		printf("argv[%d] = %s|\n", i, argv[i]);
	return (0);
}
