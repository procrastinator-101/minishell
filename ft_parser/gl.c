/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:53:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 12:50:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

# define EOMD   255

typedef union u_metadata
{
    struct
    {
        unsigned char    dq : 1;
        unsigned char    sq : 1;
        unsigned char    es : 1;
        unsigned char    uq : 1;
        unsigned char    va : 2;
        unsigned char    ex : 2;
    };
    unsigned char    holder;
}                    t_metadata;

t_metadata    *ft_metadata_create(size_t size)
{
    t_metadata    *meda;

    meda = malloc(size * sizeof(t_metadata));
    if (!meda)
        return (0);
    while (size--)
        meda[size].holder = 0;
    return (meda);
}

int main()
{
  t_metadata *meda = ft_metadata_create(20);
  meda[4].uq = 1;
  meda[4].dq = 1;
  printf("sq = %d\n", meda[4].sq);
  printf("dq = %d\n", meda[4].dq);
  printf("es = %d\n", meda[4].es);
  printf("uq = %d\n", meda[4].uq);
  printf("va = %d\n", meda[4].va);
  printf("ex = %d\n", meda[4].ex);
  printf("ex = %d\n", meda[4].holder);

  return 0;
}
