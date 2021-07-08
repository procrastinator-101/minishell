/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline_finalise.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:48:19 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 17:02:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_pipeline_finalise(t_pipeline *pipeline)
{
	int	error;

	error = ft_expand_pipeline(pipeline);
	if (error)
		return (error);
	error = ft_pipeline_extract_redirections(pipeline);
	if (error)
		return (error);
	return (ft_pipeline_getargs(pipeline));
}
