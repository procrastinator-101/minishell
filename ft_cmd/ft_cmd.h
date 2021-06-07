/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 13:33:28 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 14:55:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CMD_H
# define FT_CMD_H

# include "../ft_scmd/ft_scmd.h"

typedef struct s_cmd
{
	t_scmd			*scmd;
	struct s_cmd	*next;
}					t_cmd;

t_cmd	*ft_cmd_create(t_scmd *scmds);

void	ft_cmd_addback(t_cmd **tail, t_cmd *node);
void	ft_cmd_addfront(t_cmd **tail, t_cmd *node);
void	ft_cmd_del(t_cmd *node);
void	ft_cmd_clear(t_cmd **tail);

#endif
