/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pwd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:44:26 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/07 17:19:38 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	pwd_built(t_scmd *scmd)
{
	char	*pwd;

	if (check_options(scmd) == 1)
		return (1);
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		pwd = ft_strdup2(get_env_value("PWD"));
	}
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	free(pwd);
	return (0);
}
