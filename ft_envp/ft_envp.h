/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:22:12 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/30 18:06:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVP_H
# define FT_ENVP_H

# include <stdio.h>
# include <stdlib.h>

# include "../ft_error/ft_error.h"

typedef struct s_envp
{
	char			*name;
	char			*value;
	struct s_envp	*next;
	struct s_envp	*previous;
}					t_envp;

void				ft_envp_del(t_envp *envp);
void				ft_envp_clear(t_envp **tail);
void				ft_envp_addback(t_envp **envp, t_envp *node);
t_envp				*ft_envp_create(char *name, char *value);

#endif
