/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:33:39 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/11 11:33:42 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../ft_parser/ft_parser.h"

t_envp  *g_env;

void	free_2d(char **tabl);
int     ft_indexchr(const char *s, char a);
int     builtin(t_scmd  *scmd);
char	**list_to_tab(void);

#endif
