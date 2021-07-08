/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_finalise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:55:07 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/08 15:59:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_scmd_finalise(t_scmd *scmd)
{
	int	error;

	error = ft_expand_scmd(scmd);
	if (error)
		return (error);
	error = ft_scmd_extract_redirections(scmd);
	if (error)
		return (error);
	return (ft_scmd_getargs(scmd));
}
