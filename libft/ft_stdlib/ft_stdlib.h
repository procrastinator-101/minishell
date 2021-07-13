/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:53:27 by youness           #+#    #+#             */
/*   Updated: 2021/07/01 16:24:52 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdlib.h>
# include "../ft_ctype/ft_ctype.h"
# include "../ft_string/ft_string.h"

int		ft_atoi(const char *str);
int		ft_atoi_base(const char *str, char *base);

char	*ft_itoa(int n);
void	ft_iswap(int *a, int *b);
void	*ft_calloc(size_t count, size_t size);

#endif
