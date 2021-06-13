/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:15:49 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 19:57:24 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPELINE_H
# define FT_PIPELINE_H

# include <stdio.h>
# include <stdlib.h>

# include "../ft_scmd/ft_scmd.h"

typedef struct s_pipeline
{
	t_scmd				*scmd;
	struct s_pipeline	*next;
	char				cntrl_operator;
}						t_pipeline;

void					ft_pipeline_addback(t_pipeline **tail, \
						t_pipeline *node);
void					ft_pipeline_addfront(t_pipeline **tail, \
						t_pipeline *node);
void					ft_pipeline_del(t_pipeline *node);
void					ft_pipeline_print(t_pipeline *tail);
void					ft_pipeline_clear(t_pipeline **tail);
t_pipeline				*ft_pipeline_create(t_scmd *scmd, char cntrl_operator);

#endif
