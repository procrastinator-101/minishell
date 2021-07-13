/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:58:25 by youness           #+#    #+#             */
/*   Updated: 2021/07/01 16:38:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

# include "../ft_stdlib/ft_stdlib.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_lstadd_back(t_list **tail, t_list *new);
void				ft_lstadd_front(t_list **tail, t_list *new);
void				ft_lstdel_back(t_list **tail, void (*del)(void*));
void				ft_lstdel_front(t_list **tail, void (*del)(void*));
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **tail, void (*del)(void*));

int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);

void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));

t_list				*ft_lstnew(void *content);
t_list				*ft_lstduplicate(t_list *src, void *(*dup)(void *), \
					void (*del)(void*));

#endif
