/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:33:55 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/03 12:33:58 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_scmd/ft_scmd.h"

int	builtin(t_scmd  *scmd)
{
	if (!ft_strcmp(scmd->args[0], "echo"))
		;
	else if (!ft_strcmp(scmd->args[0], "cd"))
		;
	else if (!ft_strcmp(scmd->args[0], "pwd"))
		;
	else if (!ft_strcmp(scmd->args[0], "export"))
		;
	else if (!ft_strcmp(scmd->args[0], "unset"))
		;
	else if (!ft_strcmp(scmd->args[0], "env"))
		;
	else if (!ft_strcmp(scmd->args[0], "exit"))
		;
	else
		;
	return (0);
}
