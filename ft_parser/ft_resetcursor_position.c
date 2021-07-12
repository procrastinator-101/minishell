/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetcursor_position.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:20:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/12 20:15:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_resetcursor_position(int offset)
{
	int		i;
	int		ret;
	int		col;
	char	*up;
	char	*right;

	ret = tgetent(NULL, g_shell.terminal);
	if (ret == -1)
		return (ETERMINFO);
	else if (!ret)
		return (EUTERM);
	up = tgetstr("up", NULL);
	write(STDOUT_FILENO, up, ft_strlen(up));
	col = tgetnum("co");
	right = tgetstr("nd", NULL);
	i = -1;
	//printf("offset = %d\n", offset);
	//printf("col = %d\n", col);
	while (++i < offset % col)
		write(STDOUT_FILENO, right, ft_strlen(right));
	return (0);
}
