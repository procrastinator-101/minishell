/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:25:47 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 20:36:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	redi_dup2(t_redirection *redi, int fd)
{
	if (redi->type == RO_RDC || redi->type == ARO_RDC)
		dup2(fd, STDOUT_FILENO);
	else if (redi->type == RI_RDC)
		dup2(fd, STDIN_FILENO);
}

static char	*found_dollar(char *str, char *tmp, int i, int j)
{
	if (str[i] == '?')
	{
		tmp = ft_itoa(g_shell.scmd_status);
		i++;
	}
	else
	{
		while (str && str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '"'
			&& str[i] != '\'' && str[i] != ';')
			i++;
		tmp = ft_substr(str, j, i - j);
		tmp = free_return(ft_strdup(get_env_value(tmp)), tmp);
	}
	tmp = join_free_all(ft_substr(str, 0, j - 1), tmp);
	tmp = join_free_all(tmp, ft_substr(str, i, ft_strlen(str)));
	return (tmp);
}

static char	*check_dollar(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] != ' '
			&& str[i + 1] != '$' && str[i + 1] != '"'
			&& str[i + 1] != '\'' && str[i + 1] != ';')
		{
			i++;
			j = i;
			tmp = found_dollar(str, tmp, i, j);
			str = free_return(tmp, str);
			continue ;
		}
		i++;
	}
	return (str);
}


static int out;
/*
static void	ft_handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		close(out);
		exit(EXIT_FAILURE);
	}
}
*/

static int	here_doc_red(t_redirection *redi)
{
	char	*line;
	int		fd;
	pid_t	child;

	out = dup(STDOUT_FILENO);
	dup2(g_shell.def_out, STDOUT_FILENO);
	dup2(g_shell.def_in, STDIN_FILENO);
	g_shell.ischild_signal = 1;
	g_shell.ishere_signal = 1;
	child = fork();
	if (child == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
		fd = open("/tmp/tmp_hdoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return (print_error("/tmp/tmp_hdoc", strerror(errno), 1));
		while (1)
		{
			line = readline("> ");
			if (!line)
				break ;
			if (line && !ft_strcmp(line, redi->right_operand))
			{
				free(line);
				break ;
			}
			if (!redi->isroperand_quoted)
				line = check_dollar(line);
			ft_putendl_fd(line, fd);
			free(line);
		}
		exit(0);
	}
	waitpid(child, &fd, 0);
	g_shell.ishere_signal = 0;
	int signal = 0;
	if (WIFSIGNALED(fd))
		signal = WTERMSIG(fd);
	printf("signal = %d fd = %d isdignaled = %d\n", signal, fd, WIFSIGNALED(fd));
	ft_manage_signal_output(signal);
	g_shell.ischild_signal = 0;
	printf("hh\n");
	fd = open("/tmp/tmp_hdoc", O_RDONLY);
	if (fd < 0)
		return (print_error("/tmp/tmp_hdoc", strerror(errno), 1));
	printf("1hh\n");
	printf("dup = %d\n", dup2(fd, STDIN_FILENO));
	printf("dup2 = %d\n", dup2(out, STDOUT_FILENO));
	dup2(g_shell.def_out, STDOUT_FILENO);
	close(out);
	close(fd);
	printf("signal = %d fd = %d isdignaled = %d\n", signal, fd, WIFSIGNALED(fd));
	if (signal)
	{
		printf("2hh\n");
		g_shell.scmd_status = 1;
		return (1);
	}
	return (0);
}

int	redirection_dup(t_redirection *redi)
{
	int	fd;

	fd = 0;
	while (redi)
	{
		if (redi->type == RO_RDC)
			fd = open(redi->right_operand, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (redi->type == ARO_RDC)
			fd = open(redi->right_operand, O_CREAT | O_APPEND | O_WRONLY, 0644);
		else if (redi->type == RI_RDC)
			fd = open(redi->right_operand, O_RDONLY);
		else if (redi->type == HDOC_RDC)
			if (here_doc_red(redi) == 1)
				return (1);
		if (fd < 0)
		{
			print_error(redi->right_operand, strerror(errno), 1);
			return (1);
		}
		else if (fd != 0)
		{
			redi_dup2(redi, fd);
			close(fd);
		}
		redi = redi->next;
	}
	return (0);
}
