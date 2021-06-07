/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:02:10 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 11:01:45 by yarroubi         ###   ########.fr       */
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

#endif
