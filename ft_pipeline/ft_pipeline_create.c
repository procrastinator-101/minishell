/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:33:27 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/30 16:47:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipeline.h"

t_pipeline	*ft_pipeline_create(t_scmd *scmd, char	cntrl_operator)
{
	t_pipeline	*pipeline;

	pipeline = malloc(sizeof(t_pipeline));
	if (!pipeline)
		return (0);
	pipeline->next = 0;
	pipeline->scmd = scmd;
	pipeline->cntrl_operator = cntrl_operator;
	return (pipeline);
}
