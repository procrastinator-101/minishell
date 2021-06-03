/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipelines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:17:43 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/30 16:33:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int main()
{
	t_pipeline			*pipeline;
	t_cntrl_operator	*cntrl_operator;

	pipeline = malloc(sizeof(t_pipeline));
	pipeline->scmd = "pipe1";
	cntrl_operator = malloc(sizeof(t_cntrl_operator));
	cntrl_operator->next = 0;
	cntrl_operator->type = SEMICOLON;
	pipeline->next = cntrl_operator;
	printf("type  = %d\n", pipeline->next->type);
}
