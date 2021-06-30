/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:16:05 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/30 18:16:06 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	run_normal(t_scmd *scmd, int cmd_n)
{
	if (cmd_n > 0)
		builtin(scmd);
	else
	{
		if (fork() == 0)
		{
			builtin(scmd);
		}
		wait(NULL);
	}
	return (0);
}
