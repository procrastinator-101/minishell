/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:59:05 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/31 19:23:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "../libft/libft.h"

# define INVALID_TERMCAP		1

# define ENCQ				1		//non consistent quotes
# define ECCO				3		//ERROR CONTIGUOUS OPERATORS
# define EMAF				4		//ERROR MEMORY ALLOCATION FAILURE
# define EEONF				5		//ERROR EQAUL OPERATOR NOT FOUND

void    ft_cleanup(void);
void	ft_display_error_msg(int error);
void	ft_manage_parsing_error(int error);

#endif
