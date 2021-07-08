/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:33:55 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/07 17:26:34 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	builtin(t_scmd *scmd)
{
	if (scmd->args && scmd->args[0])
	{
		g_shell.scmd_status = 0;
		if (!ft_strcmp(scmd->args[0], "echo"))
			return (echo_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "cd"))
			return (cd_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "pwd"))
			return (pwd_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "export"))
			return (export_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "unset"))
			return (unset_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "env"))
			return (env_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "exit"))
			return (exit_built(scmd));
		else
			return (exec_ve(scmd));
	}
	return (0);
}
