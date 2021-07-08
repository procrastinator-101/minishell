/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:59:25 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/08 15:50:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_terminate(void)
{
	rl_redisplay();
	rl_on_new_line();
	ft_cleanup();
	exit(EXIT_SUCCESS);
}
