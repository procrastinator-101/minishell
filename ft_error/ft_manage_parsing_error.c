/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_parsing_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:39:09 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 12:48:16 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_manage_parsing_error(int error)
{
	if (error != EMAF)
	{
		ft_display_error_msg(error);
		return ;
	}
	ft_putendl_fd("the allocation of some block failed", STDERR_FILENO);
	ft_cleanup();
	exit(EXIT_FAILURE);
}
