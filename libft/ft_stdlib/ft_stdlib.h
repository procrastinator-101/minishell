/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:53:27 by youness           #+#    #+#             */
/*   Updated: 2021/05/05 13:59:20 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

#include <stdlib.h>
#include "../ft_ctype/ft_ctype.h"

int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	ft_iswap(int *a, int *b);
void	*ft_calloc(size_t count, size_t size);

#endif
