/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:10:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 12:30:52 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

t_redirection	*ft_redirection_create(char *left, char *right, int type)
{
	t_redirection	*redirection;

	redirection = malloc(sizeof(t_redirection));
	if (!redirection)
		return (0);
	redirection->next = 0;
	redirection->type = type;
	redirection->left_operand = left;
	redirection->right_operand = right;
	redirection->isroperand_quoted = 0;
	return (redirection);
}
