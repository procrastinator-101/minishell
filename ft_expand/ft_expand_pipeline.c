/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:17:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/11 20:46:33 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_pipeline(t_pipeline *pipeline)
{
	int		ret;
	t_scmd	*scmd;

	scmd = pipeline->scmd;
	while (scmd)
	{
		if (scmd->previous)
			g_shell.scmd_status = 0;
		ret = ft_expand_scmd(scmd);
		if (ret)
			return (ret);
		scmd = scmd->next;
	}
	return (0);
}
