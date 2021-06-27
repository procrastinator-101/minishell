/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:06:37 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/12 13:06:43 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	check_path(char *path)
{
	struct stat	st;
	int			ret;

	ret = stat(path, &st);
	if (ret == 0 && st.st_mode / 10000 != 3) // look for another method
		ret = -2;
	return (ret);
}
