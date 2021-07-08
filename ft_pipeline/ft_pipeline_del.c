/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:55:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 17:46:55 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipeline.h"

void	ft_pipeline_del(t_pipeline *node)
{
	if (!node)
		return ;
	ft_scmd_clear(&(node->scmd));
	free(node);
}
