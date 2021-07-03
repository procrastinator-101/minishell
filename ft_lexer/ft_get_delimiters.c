/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_delimiters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:09:57 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/03 19:05:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char	**ft_get_delimiters(void)
{
	char	**delimiters;

	delimiters = malloc(DELIM_SIZE * sizeof(char *));
	if (!delimiters)
		return (0);
	delimiters[0] = 0;
	delimiters[DBR_RDC] = ">>";
	delimiters[DBL_RDC] = "<<";
	delimiters[PIPE] = "|";
	delimiters[NEW_LINE] = "\n";
	delimiters[L_RDC] = "<";
	delimiters[R_RDC] = ">";
	delimiters[SPACE] = " ";
	delimiters[TAB] = "\t";
	return (delimiters);
}
