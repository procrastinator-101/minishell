/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline_extract_redirections.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:50:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 16:52:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_pipeline_extract_redirections(t_pipeline *pipeline)
{
	int		error;
	t_scmd	*scmd;

	scmd = pipeline->scmd;
	while (scmd)
	{
		error = ft_scmd_extract_redirections(scmd);
		if (error)
			return (error);
		scmd = scmd->next;
	}
	return (0);
}
