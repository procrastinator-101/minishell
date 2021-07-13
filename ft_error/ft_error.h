/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 11:59:05 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 20:19:13 by yarroubi         ###   ########.fr       */
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
# define EURDC				6		//ERROR UMBIGUOUS REDIRECT
# define EINS				7		//ERROR INCORRECT SYNTAX
# define EFPF				8		//ERROR FORKING PROCESS FAILURE
# define EOFF				9		//ERROR OPENING FILE FAILURE
# define EUTERM				10		//ERROR UNRECOGNISED TERMINAL
# define ETERMINFO			11		//ERROR TERMINFO DATABASE NOT FOUND
# define ETCID				12		//ERROR TERMINAL COULD NOT BE IDENTIFIED

# define ECSIG				13		//ERROR CHILD WAS SIGNALED

void	ft_cleanup(void);
void	ft_display_error_msg(int error);
void	ft_manage_parsing_error(int error);

#endif
