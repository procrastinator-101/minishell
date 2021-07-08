/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:53:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/08 12:24:28 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int main()
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGUSR1, SIG_IGN);
	int pid = fork();
	if (pid < 0)
	{
		printf("fork failed\n");
		return (1);
	}
	else if (pid == 0)
	{
		int num;
		signal(SIGINT, 0);
		signal(SIGQUIT, exit);
		signal(SIGUSR1, exit);
		scanf("%d", &num);
		printf("num = %d\n", num);
		if (num < 0)
			return (11);
	}
	else
	{
		int status;
		waitpid(pid, &status, WUNTRACED);
		printf("status = %d\n", status & 0xff);
		printf("exit = %d\n", WEXITSTATUS(status));
		printf("signal = %d\n", WSTOPSIG(status));
		printf("issignaled = %d\n", WIFSIGNALED(status));
	}
	return (0);
}
