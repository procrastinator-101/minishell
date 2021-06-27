/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:01:35 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/13 17:01:37 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	start_execution(t_pipeline *pipeline)
{
	while (pipeline)
	{
		while (pipeline->scmd)
		{
			builtin(pipeline->scmd);
			pipeline->scmd = pipeline->scmd->next;
		}
		pipeline = pipeline->next;
	}
}
