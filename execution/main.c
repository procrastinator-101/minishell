#include "execution.h"
#include <stdio.h>

void	copy_env(t_envp **env, char **envp)
{
	int		i;
	int		index;
	char	*tmp;
	t_envp	*node;

	i = -1;
	while (envp && envp[++i])
	{
		index = ft_indexchr(envp[i], '=');
		node = ft_envp_create(ft_substr(envp[i], 0, index),
			ft_substr(envp[i], index + 1, ft_strlen(envp[i] + index + 1)), 1);
		ft_envp_addback(env, node);
	}
}

int main(int ac, char **av, char **envp)
{
	t_envp	*env;
	t_scmd	*ar;

	copy_env(&env, envp);
	ar = malloc(sizeof(t_scmd));
	ar->args = ft_split(ft_strdup("pwd"), ' ');
	g_env = env;
	builtin(ar);
	ar->args = ft_split(ft_strdup("env"), ' ');
	//builtin(ar);
	return (0);
}