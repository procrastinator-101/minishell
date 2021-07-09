# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 21:04:47 by yarroubi          #+#    #+#              #
#    Updated: 2021/05/25 14:52:49 by yarroubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_string.a

SRC = ft_bzero.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strndup.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strrstr.c \
	  ft_strtrim.c \
	  ft_substr.c

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
