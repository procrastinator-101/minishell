/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 17:22:12 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 18:19:57 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVP_H
# define FT_ENVP_H

# include <stdio.h>
# include <stdlib.h>

# include "../ft_error/ft_error.h"
# include <sys/errno.h>
# include <string.h>

typedef struct s_envp
{
	char			*name;
	char			*value;
	int				isenv;
	struct s_envp	*next;
	struct s_envp	*previous;
}					t_envp;

void				ft_envp_del(t_envp *envp);
void				ft_envp_print(t_envp *tail);
void				ft_envp_clear(t_envp **tail);
void				ft_envp_addback(t_envp **envp, t_envp *node);
void				ft_envp_setvalue(t_envp *envp, char *name, char *value);
char				*ft_envp_getvalue(t_envp *envp, char *name);
t_envp				*ft_envp_create(char *name, char *value, int isenv);
t_envp				*ft_char_to_envp(char *str, int *error, int isenv);
t_envp				*ft_load_sys_envp(char **sys_envp, int *error);

#endif
