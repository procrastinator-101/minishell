/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_signal_output.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:24:23 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/08 20:00:57 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_manage_signal_output(int signal)
{
	if (!signal)
		return ;
	if (signal == SIGQUIT)
	{
		ft_putstr_fd("Quit: ", STDOUT_FILENO);
		ft_putnbr_fd(SIGQUIT, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
	}
	else if (signal == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
}
