/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 19:51:31 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 19:56:47 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipeline.h"

void	ft_pipeline_print(t_pipeline *tail)
{
	t_pipeline	*head;

	head = tail;
	while (head)
	{
		printf("IIIIIIIIIIIIIIIIIIIIIIII PIPELINE IIIIIIIIIIIIIIIIIIIIIIII\n");
		ft_scmd_print(head->scmd);
		ft_token_print_type(head->cntrl_operator);
		head = head->next;
		printf("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");
	}
}
