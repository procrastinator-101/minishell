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

// int	exit_built(t_scmd *scmd)
// {
// 	if (tablen(scmd->args) == 2)
// 	{
// 		// % 256
// 		// if no arg use g_sell.pipelinestatus
// 	}
// 	else
// 	{
// 		// if first num : exit: too many arguments // do nothing // $? 1
// 		// else exit: --456: numeric argument required // exit // $? 255
// 	}
// }

int	builtin(t_scmd *scmd)
{
	if (scmd->args && scmd->args[0])
	{
		g_shell.scmd_status = 0;
		if (!ft_strcmp(scmd->args[0], "echo"))	//done (I guess)
			return (echo_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "cd"))	//done
			return (cd_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "pwd"))	//done (I guess)
			return (pwd_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "export"))	//done (I guess)
			return (export_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "unset"))	//done
			return (unset_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "env"))	//done (I guess)
			return (env_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "exit"))
			;
		else
			return (exec_ve(scmd));	//done (I guess)
	}
	return (0);
}
