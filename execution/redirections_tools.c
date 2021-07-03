/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:25:47 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/03 20:01:38 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	redi_dup2(t_redirection *redi, int fd)
{
	if (redi->type == R_RDC || redi->type == DBR_RDC)
		dup2(fd, STDOUT_FILENO);
	else if (redi->type == L_RDC)
		dup2(fd, STDIN_FILENO);
}

static char	*check_dollar(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')	//check leacks
		{
			// printf("**%s\n", str);
			i++;
			j = i;
			while (str[i] && str[i] != ' ' && str[i] != '$')
				i++;
			tmp = ft_substr(str, j, i - j);
			// printf("1 %s| %d j=%d\n", tmp, i, j);
			tmp = get_env_value(tmp);
			// printf("2 %s\n", tmp);
			tmp = ft_strjoin(ft_substr(str, 0, j - 1), tmp);
			// printf("3 %s\n", tmp);
			tmp = ft_strjoin(tmp, ft_substr(str, i, ft_strlen(str)));
			// printf("4 %s\n", tmp);
			// printf("..\n");
			i = 0;
			str = tmp;
			continue ;
		}
		i++;
	}
	return (str);
}

static int	here_doc_red(t_redirection *redi)
{
	char	*line;
	int		fd;

	fd = open("/tmp/tmp_hdoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		print_error("/tmp/tmp_hdoc", strerror(errno), 1);
		return (1);
	}
	while (1)
	{
		line = readline("> ");
		if (!ft_strcmp(line, redi->right_operand))
		{
			free(line);
			break ;
		}
		line = check_dollar(line);
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	fd = open("/tmp/tmp_hdoc", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirection_dup(t_redirection *redi)
{
	int	fd;

	fd = 0;
	while (redi)
	{
		if (redi->type == R_RDC)
			fd = open(redi->right_operand, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else if (redi->type == DBR_RDC)
			fd = open(redi->right_operand, O_CREAT | O_APPEND | O_WRONLY, 0644);
		else if (redi->type == L_RDC)
		 	fd = open(redi->right_operand, O_RDONLY);
		else if (redi->type == DBL_RDC)
			return (here_doc_red(redi));
		if (fd < 0)
		{
			print_error(redi->right_operand, strerror(errno), 1);
			return (1);
		}
		redi_dup2(redi, fd);
		close(fd);
		redi = redi->next;
	}
	return (0);
}
