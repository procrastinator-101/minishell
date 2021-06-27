/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:31:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/27 18:23:51 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scmd.h"

t_scmd	*ft_scmd_create(t_token *tokens, char **args, t_redirection *rdcs)
{
	t_scmd	*scmd;

	scmd = malloc(sizeof(t_scmd));
	if (!scmd)
		return (0);
	scmd->args = args;
	scmd->tokens = tokens;
	scmd->redirections = rdcs;
	scmd->next = 0;
	scmd->previous = 0;
	return (scmd);
}
