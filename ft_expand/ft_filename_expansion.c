/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filename_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <yarroubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:51:23 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/26 19:39:25 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"
# include <dirent.h>

# include <errno.h>

t_shell		g_shell;


/*
**	quote removal is done simultaneoulsy with filename expansion to speed
**	things up
**	the token's previous and next tokens might change so they have to be handeled
**	properly
*/

int ft_wildcard_match(char *pattern, char *str, t_metadata *meda)
{
	while (*pattern)
	{
		if (meda->uq && ft_isquote(*pattern))
		{
			pattern++;
			meda++;
			continue ;
		}
		if (*pattern == '*')
		{
			if (ft_wildcard_match(pattern + 1, str, meda + 1))
				return (1);
			if (!*str)
				return (0);
		}
		else
		{
			if (*pattern != *str)
				return (0);
			pattern++;
			meda++;
		}
		str++;
	}
	return (!*str);
}

static t_token	*ft_getmatch(t_token *pattern, char *filename)
{
	t_token	*token;

	token =  malloc(sizeof(t_token));
	if (!token)
		return (0);
	token->str = ft_strdup(filename);
	token->meda = 0;
	token->type = pattern->type;
	token->next = 0;
	token->hasquotes = pattern->hasquotes;
	if (!token->str)
		ft_token_harddel(&token);
	return (token);
}

static int	ft_addnext_match(t_token **tokens, t_token *pattern, DIR *wd)
{
	t_token			*token;
	struct dirent	*file;

	errno = 0;
	file = readdir(wd);
	if (errno)
		return (EDRF);
	if (!file)
		return (-1);
	//printf("-->>|%s|{%s}\n", file->d_name, pattern->str);
	if (!ft_strcmp(".", file->d_name) || !ft_strcmp("..", file->d_name))
		return (0);
	if (ft_wildcard_match(pattern->str, file->d_name, pattern->meda))
	{
		//printf("ok\n");
		token = ft_getmatch(pattern, file->d_name);
		if (!token)
			return (EMAF);
		else
			ft_token_addback(tokens, token);
	}
	//printf("ok1\n");
	return (0);
}

t_token	*ft_filename_expansion(t_token *token, int *error)
{
	DIR				*wd;
	t_token			*tokens;

	*error = 0;
	tokens = 0;
	wd = opendir(".");
	while (!*error)
		*error = ft_addnext_match(&tokens, token, wd);
	if (*error == -1)
		*error = 0;
	closedir(wd);
	if (tokens || *error)
		ft_token_del(token);
	else
		tokens = ft_quote_removal(token);
	if (*error)
		ft_token_clear(&tokens);
	return (tokens);
}

int main(int argc, char **argv)
{
	t_token	*tokens;
	int error;

	if (argc < 2)
		return 0;
	ft_bzero(&g_shell, sizeof(t_shell));
	g_shell.delimiters = ft_get_delimiters();
	tokens = ft_lexer(argv[1], ft_strlen(argv[1]) + 1, &error);
	printf("error : %d\n", error);
	if (!error)
	{
		ft_token_print(tokens);
		printf("\n\n+++++++++++++++++++++++++++++++++++++++++\n");
		tokens = ft_filename_expansion(tokens, &error);
		printf("\n+++++++++++++++++++++++++++++++++++++++++\n\n");
		if (errno)
			printf("error : %d\n", error);
		ft_token_print(tokens);
	}
	return (0);
}
