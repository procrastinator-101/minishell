/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metadata.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:21:59 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 14:40:29 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_METADATA_H
# define FT_METADATA_H

/*
 **
 ** the end of a metadata sequence is defined by holder to 255
 **
*/

# include <stdio.h>
# include <stdlib.h>

# include "../libft/libft.h"

# define SINGLE_QUOTED		's'
# define DOUBLE_QUOTED		'd'
# define ESCAPED			'e'
# define UNQUOTED			'u'

# define EOMD	255

typedef union u_metadata
{
	struct
	{
		unsigned char	dq : 1;
		unsigned char	sq : 1;
		unsigned char	es : 1;
		unsigned char	uq : 1;
		unsigned char	va : 2;
		unsigned char	ex : 2;
	};
	unsigned char	holder;
}					t_metadata;

char				ft_getquote(t_metadata meda);
void				ft_metadata_print(t_metadata *meda);
void				ft_metadata_set(t_metadata *meda, int quote, int \
					var_assignment, int isfrom_expns);

t_metadata			*ft_metadata_create(size_t size);
t_metadata			*ft_metadata_dup(t_metadata *meda);
t_metadata			*ft_metadata_ndup(t_metadata *meda, size_t n);
t_metadata			*ft_metadata_nappend(t_metadata *m1, t_metadata *m2, \
					size_t n);
t_metadata			*ft_get_unimetadata(size_t size, int quote, int va, \
					int expns);

#endif
