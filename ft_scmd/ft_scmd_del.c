/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:37:40 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 14:50:19 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scmd.h"

void	ft_scmd_del(t_scmd *node)
{
	int	i;

	if (!node)
		return ;
	i = -1;
	while (node->args && node->args[++i])
		free(node->args[i]);
	free(node->args);
	ft_token_clear(&(node->tokens));
	ft_redirection_clear(&(node->redirections));
	free(node);
}
