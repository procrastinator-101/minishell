/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_delimiters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 19:09:57 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 10:52:30 by yarroubi         ###   ########.fr       */
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
	delimiters[ARO_RDC] = ">>";
	delimiters[HDOC_RDC] = "<<";
	delimiters[PIPE] = "|";
	delimiters[NEW_LINE] = "\n";
	delimiters[RI_RDC] = "<";
	delimiters[RO_RDC] = ">";
	delimiters[SPACE] = " ";
	delimiters[TAB] = "\t";
	return (delimiters);
}
