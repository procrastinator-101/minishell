/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:59:05 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 12:57:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "../libft/libft.h"

# define ENCQ				1		//non consistent quotes
# define ECCO				2		//ERROR CONTIGUOUS OPERATORS
# define EMAF				3		//ERROR MEMORY ALLOCATION FAILURE
# define EEONF				4		//ERROR EQAUL OPERATOR NOT FOUND
# define EURDC				5		//ERROR UMBIGUOUS REDIRECT
# define EFPF				6		//ERROR FORKING PROCESS FAILURE
# define EOFF				7		//ERROR OPENING FILE FAILURE
# define EDRF               8       //ERROR DIRECTORY READING FAILURE
# define EUTERM				9		//ERROR UNRECOGNISED TERMINAL
# define ETERMINFO			10		//ERROR TERMINFO DATABASE NOT FOUND
# define ETCID				11		//ERROR TERMINAL COULD NOT BE IDENTIFIED
# define ETERCAP			12		//ERROR TERMCAP RELATED PROBLEM

# define ECSIG				13		//ERROR CHILD WAS SIGNALED

void	ft_cleanup(void);
void	ft_display_error_msg(int error);
void	ft_manage_parsing_error(int error);

#endif
