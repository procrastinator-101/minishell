/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:06:29 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/02 17:06:31 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	print_error(char *path, char *er, int err_num)
{
	ft_display_error_msg(0);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(er, 2);
	g_shell.scmd_status = err_num;
	return (1);
}

int	print_error_2(char *path, char *data, char *er, int err_num)
{
	ft_display_error_msg(0);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(er, 2);
	g_shell.scmd_status = err_num;
	return (1);
}

int	print_error_3(char *path, char *data, char *er, int err_num)
{
	ft_display_error_msg(0);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(data, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(er, 2);
	g_shell.scmd_status = err_num;
	return (1);
}

void	exit_failure(char *fonc)
{
	print_error(fonc, strerror(errno), 1);
	exit(1);
}
