/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_parsing_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:39:09 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 19:23:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_manage_parsing_error(int error)
{
	//save the added hsitorty lines
	ft_display_error_msg(error);
	ft_cleanup();
	exit(EXIT_FAILURE);
}
