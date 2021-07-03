/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:24:37 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/01 17:24:56 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	def_in_out(void)
{
	g_shell.def_in = dup(STDIN_FILENO);
	g_shell.def_out = dup(STDOUT_FILENO);
}

void	reset_in_out(void)
{
	dup2(g_shell.def_in, STDIN_FILENO);
	dup2(g_shell.def_out, STDOUT_FILENO);
}

static void	redi_dup2(t_redirection *redi, int fd)
{
	if (redi->type == R_RDC || redi->type == DBR_RDC)
		dup2(fd, STDOUT_FILENO);
	else if (redi->type == L_RDC)
		dup2(fd, STDIN_FILENO);
}

int	redirection_dup(t_redirection *redi)
{
	int	fd;

	fd = 0;
	while (redi)
	{
		if (redi->type == R_RDC)
			fd = open(redi->right_operand, O_CREAT | O_WRONLY, 0644);
		else if (redi->type == DBR_RDC)
			fd = open(redi->right_operand, O_CREAT | O_APPEND | O_WRONLY, 0644);
		else if (redi->type == L_RDC)
			fd = open(redi->right_operand, O_RDONLY);
		if (fd < 0)
		{
			print_error(redi->right_operand, strerror(errno), 1);	//check here
			return (1);
		}
		redi_dup2(redi, fd);
		close(fd);
		redi = redi->next;
	}
	return (0);
}
