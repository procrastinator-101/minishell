# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 21:04:47 by yarroubi          #+#    #+#              #
#    Updated: 2021/05/05 15:38:23 by youness          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_LST_PATH = ft_lst
FT_MATH_PATH = ft_math
FT_CTYPE_PATH = ft_ctype
FT_STDIO_PATH = ft_stdio
FT_STDLIB_PATH = ft_stdlib
FT_STRING_PATH = ft_string
FT_ALGORITHMS_PATH = ft_algorithms

FT_LST_LIB = $(FT_LST_PATH)/ft_lst.a
FT_MATH_LIB = $(FT_MATH_PATH)/ft_math.a
FT_CTYPE_LIB = $(FT_CTYPE_PATH)/ft_ctype.a
FT_STDIO_LIB = $(FT_STDIO_PATH)/ft_stdio.a
FT_STDLIB_LIB = $(FT_STDLIB_PATH)/ft_stdlib.a
FT_STRING_LIB = $(FT_STRING_PATH)/ft_string.a
FT_ALGORITHMS_LIB = $(FT_ALGORITHMS_PATH)/ft_algorithms.a


FT_LST_SRC = $(FT_LST_PATH)/ft_lstadd_back.c \
			 $(FT_LST_PATH)/ft_lstadd_front.c \
			 $(FT_LST_PATH)/ft_lstclear.c \
			 $(FT_LST_PATH)/ft_lstdel_back.c \
			 $(FT_LST_PATH)/ft_lstdel_front.c \
			 $(FT_LST_PATH)/ft_lstdelone.c \
			 $(FT_LST_PATH)/ft_lstduplicate.c \
			 $(FT_LST_PATH)/ft_lstiter.c \
			 $(FT_LST_PATH)/ft_lstlast.c \
			 $(FT_LST_PATH)/ft_lstmap.c \
			 $(FT_LST_PATH)/ft_lstnew.c \
			 $(FT_LST_PATH)/ft_lstsize.c

FT_MATH_SRC = $(FT_MATH_PATH)/ft_dmax.c \
			  $(FT_MATH_PATH)/ft_dmin.c \
			  $(FT_MATH_PATH)/ft_max.c \
			  $(FT_MATH_PATH)/ft_min.c \
			  $(FT_MATH_PATH)/ft_umax.c \
			  $(FT_MATH_PATH)/ft_umin.c

FT_CTYPE_SRC = $(FT_CTYPE_PATH)/ft_isalnum.c \
			   $(FT_CTYPE_PATH)/ft_isalpha.c \
			   $(FT_CTYPE_PATH)/ft_isascii.c \
			   $(FT_CTYPE_PATH)/ft_isdigit.c \
			   $(FT_CTYPE_PATH)/ft_isnumber.c \
			   $(FT_CTYPE_PATH)/ft_isprint.c \
			   $(FT_CTYPE_PATH)/ft_issign.c \
			   $(FT_CTYPE_PATH)/ft_isspace.c \
			   $(FT_CTYPE_PATH)/ft_tolower.c \
			   $(FT_CTYPE_PATH)/ft_toupper.c

FT_STDIO_SRC = $(FT_STDIO_PATH)/ft_putchar_fd.c \
			   $(FT_STDIO_PATH)/ft_putendl_fd.c \
			   $(FT_STDIO_PATH)/ft_putnbr_fd.c \
			   $(FT_STDIO_PATH)/ft_putstr_fd.c

FT_STDLIB_SRC = $(FT_STDLIB_PATH)/ft_atoi.c \
				$(FT_STDLIB_PATH)/ft_calloc.c \
				$(FT_STDLIB_PATH)/ft_iswap.c \
				$(FT_STDLIB_PATH)/ft_itoa.c

FT_STRING_SRC = $(FT_STRING_PATH)/ft_bzero.c \
				$(FT_STRING_PATH)/ft_memccpy.c \
				$(FT_STRING_PATH)/ft_memchr.c \
				$(FT_STRING_PATH)/ft_memcmp.c \
				$(FT_STRING_PATH)/ft_memcpy.c \
				$(FT_STRING_PATH)/ft_memmove.c \
				$(FT_STRING_PATH)/ft_memset.c \
				$(FT_STRING_PATH)/ft_split.c \
				$(FT_STRING_PATH)/ft_strchr.c \
				$(FT_STRING_PATH)/ft_strcmp.c \
				$(FT_STRING_PATH)/ft_strdup.c \
				$(FT_STRING_PATH)/ft_strjoin.c \
				$(FT_STRING_PATH)/ft_strlcat.c \
				$(FT_STRING_PATH)/ft_strlcpy.c \
				$(FT_STRING_PATH)/ft_strlen.c \
				$(FT_STRING_PATH)/ft_strmapi.c \
				$(FT_STRING_PATH)/ft_strncmp.c \
				$(FT_STRING_PATH)/ft_strnstr.c \
				$(FT_STRING_PATH)/ft_strrchr.c \
				$(FT_STRING_PATH)/ft_strrstr.c \
				$(FT_STRING_PATH)/ft_strtrim.c \
				$(FT_STRING_PATH)/ft_substr.c

FT_ALGORITHMS_SRC = $(FT_ALGORITHMS_PATH)/ft_quick_sort.c

all: $(NAME)

$(NAME): $(SUB_ARCHIVES)
	@ar -rc $(NAME) $(SUB_ARCHIVES) ; ranlib $(NAME)

$(FT_LST):
	$(MAKE) -C $(FT_LST_PATH)

$(FT_MATH):
	$(MAKE) -C $(FT_MATH_PATH)

$(FT_CTYPE):
	$(MAKE) -C $(FT_CTYPE_PATH)

$(FT_STDIO):
	$(MAKE) -C $(FT_STDIO_PATH)

$(FT_STDLIB):
	$(MAKE) -C $(FT_STDLIB_PATH)

$(FT_STRING):
	$(MAKE) -C $(FT_STRING_PATH)

$(FT_ALGORITHMS):
	$(MAKE) -C $(FT_ALGORITHMS_PATH)

clean:
	$(MAKE) -C $(FT_LST_PATH) fclean
	$(MAKE) -C $(FT_MATH_PATH) fclean
	$(MAKE) -C $(FT_CTYPE_PATH) fclean
	$(MAKE) -C $(FT_STDIO_PATH) fclean
	$(MAKE) -C $(FT_STDLIB_PATH) fclean
	$(MAKE) -C $(FT_STRING_PATH) fclean
	$(MAKE) -C $(FT_ALGORITHMS_PATH) fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
