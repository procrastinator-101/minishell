/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:53:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/29 19:31:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **sys_env)
{
	for (int i = 0; sys_env[i]; i++)
		printf("%s\n", sys_env[i]);
	return (0);
}
