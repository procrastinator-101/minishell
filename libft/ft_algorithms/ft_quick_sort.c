/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 00:37:20 by youness           #+#    #+#             */
/*   Updated: 2021/07/01 16:37:11 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"

static int	ft_partition(int *arr, int size)
{
	int	l;
	int	h;
	int	pivot;

	pivot = arr[0];
	l = 0;
	h = size;
	while (l < h)
	{
		l++;
		h--;
		while (l < size && arr[l] < pivot)
			l++;
		while (h >= 0 && arr[h] > pivot)
			h--;
		if (l < h)
			ft_iswap(arr + h, arr + l);
	}
	ft_iswap(arr + h, arr);
	return (h);
}

void	ft_quick_sort(int *arr, int size)
{
	int	p;

	if (size < 2)
		return ;
	p = ft_partition(arr, size);
	ft_quick_sort(arr, p);
	ft_quick_sort(arr + p + 1, size - p - 1);
}
