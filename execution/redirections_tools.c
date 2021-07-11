/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 17:25:47 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/11 20:36:36 by yarroubi         ###   ########.fr       */
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

static int	here_doc_red(t_redirection *redirection)
{
	int	fd;

	fd = open(redirection->file_name, O_RDONLY);
	if (fd < 0)
		return (print_error(redirection->file_name, strerror(errno), 1));
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
