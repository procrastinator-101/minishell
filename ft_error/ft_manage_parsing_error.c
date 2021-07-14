/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_parsing_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:39:09 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 13:28:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_manage_parsing_error(int error)
{
	if (error == ECSIG)
		return ;
	ft_display_error_msg(error);
	if (error == EMAF || error == EFPF || error == EOFF || error == EUTERM)
	{
		ft_cleanup();
		exit(EXIT_FAILURE);
	}
	else if (error == ETERMINFO || error == ETCID || error == ETERCAP)
	{
		ft_cleanup();
		exit(EXIT_FAILURE);
	}
}
