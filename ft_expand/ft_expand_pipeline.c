/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_pipeline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:17:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 14:41:04 by yarroubi         ###   ########.fr       */
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
		ret = ft_expand_scmd(scmd);
		if (ret)
			return (ret);
		scmd = scmd->next;
	}
	return (0);
}
