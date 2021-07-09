# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 21:04:47 by yarroubi          #+#    #+#              #
#    Updated: 2021/05/05 14:54:32 by youness          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_lst.a

SRC = ft_lstadd_back.c \
	  ft_lstadd_front.c \
	  ft_lstclear.c \
	  ft_lstdel_back.c \
	  ft_lstdel_front.c \
	  ft_lstdelone.c \
	  ft_lstduplicate.c \
	  ft_lstiter.c \
	  ft_lstlast.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_lstsize.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJ)
	@ar -rc $(NAME) $(OBJ) ; ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
