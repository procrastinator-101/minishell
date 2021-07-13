/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:33:39 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 13:47:55 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../ft_parser/ft_parser.h"
# include <sys/stat.h>
# include <readline/readline.h>
# include <dirent.h>

int		builtin(t_scmd *scmd);
int		cd_built(t_scmd *scmd);
int		pwd_built(t_scmd *scmd);
int		env_built(t_scmd *scmd);
int		echo_built(t_scmd *scmd);
int		unset_built(t_scmd *scmd);
int		export_built(t_scmd *scmd);
int		exit_built(t_scmd *scmd);

int		run_infork(t_scmd *scmd);
int		run_normal(t_scmd *scmd, int cmd_n);
int		start_execution(t_pipeline *pipeline);

int		env_size(void);
int		ft_isenv(char *name);
int		check_path(char *path, int ret);
char	*get_env_value(char *name);
void	ft_set_isenv(char *name, int isenv);

char	*checkalloc(char *str);
void	free_2d(char **tabl);
char	*join_free_s1(char *s1, char *s2);
char	*join_free_all(char *s1, char *s2);
char	*free_return(char *to_ret, char *to_free);

int		tablen(char **tabl);
char	**listenvp_to_tab(void);
void	sort_table(char **table, int table_size);

void	def_in_out(void);
void	reset_in_out(void);

int		exec_ve(t_scmd *scmd);
int		redirection_dup(t_redirection *redi);

char	*ft_strdup2(const char *src);

int		print_error(char *path, char *er, int err_num);
int		print_error_2(char *path, char *data, char *er, int err_num);
int		print_error_3(char *path, char *data, char *er, int err_num);
void	exit_failure(char *fonc);

int		look_for_equal(char *data);
int		look_for_slach(char *data);
int		check_options(t_scmd *scmd);
char	*catch_null_ordup(char *str);

int		catch_child_exitstatus(int wstatus, int lastpid, int pid);

void	ft_manage_signal_output(int signal);

#endif
