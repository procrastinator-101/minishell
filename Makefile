# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 21:04:47 by yarroubi          #+#    #+#              #
#    Updated: 2021/06/03 11:02:37 by yarroubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = libft/libft.a


FT_LEXER_PATH = ft_lexer
FT_ERROR_PATH = ft_error
FT_PARSER_PATH = ft_parser

FT_ENVP_PATH = ft_envp
FT_SCMD_PATH = ft_scmd
FT_TOKEN_PATH = ft_token
FT_PIPELINE_PATH = ft_pipeline

FT_SUPPORT_FUNCTIONS_PATH = ft_support_functions



FT_PARSER_SRC = $(FT_PARSER_PATH)/ft_cleanup.c \
				$(FT_PARSER_PATH)/ft_initialise_shell.c \
				$(FT_PARSER_PATH)/ft_get_cmd_tree.c \
				$(FT_PARSER_PATH)/ft_parser.c \
				$(FT_PARSER_PATH)/ft_tokens_to_pipeline.c \
				$(FT_PARSER_PATH)/ft_tokens_to_scmd.c \
				$(FT_PARSER_PATH)/main.c

FT_LEXER_SRC = $(FT_LEXER_PATH)/ft_check_syntax.c \
			   $(FT_LEXER_PATH)/ft_find_delimiter.c \
			   $(FT_LEXER_PATH)/ft_get_delimiters.c \
			   $(FT_LEXER_PATH)/ft_identify_rdc_operands.c \
			   $(FT_LEXER_PATH)/ft_isblank.c \
			   $(FT_LEXER_PATH)/ft_iscntrl_operator.c \
			   $(FT_LEXER_PATH)/ft_isname.c \
			   $(FT_LEXER_PATH)/ft_isoperator.c \
			   $(FT_LEXER_PATH)/ft_isredirection.c \
			   $(FT_LEXER_PATH)/ft_lexer.c \
			   $(FT_LEXER_PATH)/ft_process_backslash.c \
			   $(FT_LEXER_PATH)/ft_process_cstyle_quoting.c \
			   $(FT_LEXER_PATH)/ft_process_double_quotes.c \
			   $(FT_LEXER_PATH)/ft_process_quotes.c \
			   $(FT_LEXER_PATH)/ft_process_single_quotes.c \
			   $(FT_LEXER_PATH)/ft_strtok.c \
			   $(FT_LEXER_PATH)/ft_tokenise.c

FT_ERROR_SRC = $(FT_ERROR_PATH)/ft_display_error_msg.c \
			   $(FT_ERROR_PATH)/ft_manage_parsing_error.c

FT_TOKEN_SRC = $(FT_TOKEN_PATH)/ft_token_addback.c \
			   $(FT_TOKEN_PATH)/ft_token_clear.c \
			   $(FT_TOKEN_PATH)/ft_token_create.c \
			   $(FT_TOKEN_PATH)/ft_token_del.c \
			   $(FT_TOKEN_PATH)/ft_token_harddel.c \
			   $(FT_TOKEN_PATH)/ft_token_print.c \
			   $(FT_TOKEN_PATH)/ft_token_print_type.c

FT_ENVP_SRC = $(FT_ENVP_PATH)/ft_char_to_envp.c \
			  $(FT_ENVP_PATH)/ft_envp_addback.c \
			  $(FT_ENVP_PATH)/ft_envp_clear.c \
			  $(FT_ENVP_PATH)/ft_envp_create.c \
			  $(FT_ENVP_PATH)/ft_envp_del.c

FT_SCMD_SRC = $(FT_SCMD_PATH)/ft_scmd_addback.c \
			  $(FT_SCMD_PATH)/ft_scmd_addfront.c \
			  $(FT_SCMD_PATH)/ft_scmd_clear.c \
			  $(FT_SCMD_PATH)/ft_scmd_create.c \
			  $(FT_SCMD_PATH)/ft_scmd_del.c \
			  $(FT_SCMD_PATH)/ft_scmd_print.c

FT_PIPELINE_SRC = $(FT_PIPELINE_PATH)/ft_pipeline_addback.c \
				  $(FT_PIPELINE_PATH)/ft_pipeline_addfront.c \
				  $(FT_PIPELINE_PATH)/ft_pipeline_clear.c \
				  $(FT_PIPELINE_PATH)/ft_pipeline_create.c \
				  $(FT_PIPELINE_PATH)/ft_pipeline_del.c \
				  $(FT_PIPELINE_PATH)/ft_pipeline_print.c

FT_SUPPORT_FUNCTIONS_SRC = $(FT_SUPPORT_FUNCTIONS_PATH)/ft_append_character.c \
						   $(FT_SUPPORT_FUNCTIONS_PATH)/ft_traverse_spaces.c

SRC = $(FT_PARSER_SRC) $(FT_LEXER_SRC) $(FT_ERROR_SRC) $(FT_TOKEN_SRC) \
	  $(FT_ENVP_SRC) $(FT_SCMD_SRC) $(FT_PIPELINE_SRC) $(FT_SUPPORT_FUNCTIONS_SRC)

OBJ = $(SRC:.c=.o)

LIB = $(LIBFT)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):$(OBJ) $(LIB)
	@gcc -o $@ $(OBJ) $(LIB)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

$(LIBFT) :
	@$(MAKE) -C libft

clean:
	@rm -rf $(OBJ)
	@$(MAKE) -C libft fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
