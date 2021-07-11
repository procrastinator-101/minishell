/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_execute_heredocs.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:47:28 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/11 20:28:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_scmd_execute_heredocs(t_scmd *scmd, int *id)
{
	int				ret;
	t_scmd			*head;
	t_redirection	*redirection;

	ret = 0;
	head = scmd;
	while (head)
	{
		redirection = head->redirections;
		while (redirection)
		{
			if (redirection->type == HDOC_RDC)
			{
				(*id)++;
				ret = ft_redirection_execute_heredoc(redirection, *id);
				if (ret)
					return (ret);
			}
			redirection = redirection->next;
		}
		head = head->next;
	}
	return (ret);
}
