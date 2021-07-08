/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline_getargs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:56:52 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 17:06:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_pipeline_getargs(t_pipeline *pipeline)
{
	int		error;
	t_scmd	*scmd;

	scmd = pipeline->scmd;
	while (scmd)
	{
		error = ft_scmd_getargs(scmd);
		if (error)
			return (error);
		scmd = scmd->next;
	}
	return (0);
}
