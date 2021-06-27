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
# include <sys/stat.h>

int		echo_built(t_scmd *scmd);
int		pwd_built(void);
int		env_built(t_scmd *scmd);
int		check_path(char *path);
char	*get_env_value(char *name);
void	free_2d(char **tabl);
char	*join_free_s1(char *s1, char *s2);
int		ft_indexchr(const char *s, char a);
int		builtin(t_scmd *scmd);
char	**listenvp_to_tab(void);
char	*tab_to_line(char **tabl);
int		tablen(char **tabl);
void	start_execution(t_pipeline *pipeline);

#endif
