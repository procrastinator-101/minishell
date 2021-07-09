/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:20:43 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 15:21:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

void	ft_redirection_del(t_redirection *node)
{
	if (!node)
		return ;
	free(node->left_operand);
	free(node->right_operand);
	free(node);
}
