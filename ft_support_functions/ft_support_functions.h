/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:02:10 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 10:37:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUPPORT_FUNCTIONS_H
# define FT_SUPPORT_FUNCTIONS_H

# include <stdlib.h>
# include "../libft/libft.h"

int		ft_traverse_spaces(char *str);
int		ft_strichr(char *str, char c);
char	*ft_append_character(char *str, char c);
char	*ft_strnappend(char *s1, char *s2, size_t n);

int		ft_atoi_length(char *str, int *len);
char	**ft_split(char const *s, char c);

#endif
