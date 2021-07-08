# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 21:04:47 by yarroubi          #+#    #+#              #
#    Updated: 2021/07/08 16:02:18 by yarroubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT = libft/libft.a


FT_LEXER_PATH = ft_lexer
FT_ERROR_PATH = ft_error
FT_PARSER_PATH = ft_parser
FT_EXPAND_PATH = ft_expand

FT_ENVP_PATH = ft_envp
FT_SCMD_PATH = ft_scmd
FT_TOKEN_PATH = ft_token
EXECUTION_PATH = execution
FT_METADATA_PATH = ft_metadata
FT_PIPELINE_PATH = ft_pipeline
FT_REDIRECTION_PATH = ft_redirection

FT_SUPPORT_FUNCTIONS_PATH = ft_support_functions



FT_PARSER_SRC = $(FT_PARSER_PATH)/ft_cleanup.c \
				$(FT_PARSER_PATH)/ft_get_cmd_tree.c \
				$(FT_PARSER_PATH)/ft_initialise_shell.c \
				$(FT_PARSER_PATH)/ft_install_child_signal_handlers.c \
				$(FT_PARSER_PATH)/ft_install_parent_signal_handlers.c \
				$(FT_PARSER_PATH)/ft_parser.c \
				$(FT_PARSER_PATH)/ft_pipeline_extract_redirections.c \
				$(FT_PARSER_PATH)/ft_pipeline_finalise.c \
				$(FT_PARSER_PATH)/ft_pipeline_getargs.c \
				$(FT_PARSER_PATH)/ft_scmd_extract_redirections.c \
				$(FT_PARSER_PATH)/ft_scmd_finalise.c \
				$(FT_PARSER_PATH)/ft_scmd_getargs.c \
				$(FT_PARSER_PATH)/ft_terminate.c \
				$(FT_PARSER_PATH)/ft_tokens_to_pipeline.c \
				$(FT_PARSER_PATH)/ft_tokens_to_scmd.c \
				$(FT_PARSER_PATH)/main.c

FT_LEXER_SRC = $(FT_LEXER_PATH)/ft_check_syntax.c \
			   $(FT_LEXER_PATH)/ft_find_delimiter.c \
			   $(FT_LEXER_PATH)/ft_get_delimiters.c \
			   $(FT_LEXER_PATH)/ft_get_name.c \
			   $(FT_LEXER_PATH)/ft_identify_rdc_operands.c \
			   $(FT_LEXER_PATH)/ft_isblank.c \
			   $(FT_LEXER_PATH)/ft_iscntrl_operator.c \
			   $(FT_LEXER_PATH)/ft_isname.c \
			   $(FT_LEXER_PATH)/ft_isoperator.c \
			   $(FT_LEXER_PATH)/ft_isquote.c \
			   $(FT_LEXER_PATH)/ft_isquoted.c \
			   $(FT_LEXER_PATH)/ft_isrdc_operand.c \
			   $(FT_LEXER_PATH)/ft_isrdc_operator.c \
			   $(FT_LEXER_PATH)/ft_isword.c \
			   $(FT_LEXER_PATH)/ft_lexer.c \
			   $(FT_LEXER_PATH)/ft_process_cstyle_quoting.c \
			   $(FT_LEXER_PATH)/ft_process_double_quotes.c \
			   $(FT_LEXER_PATH)/ft_process_quotes.c \
			   $(FT_LEXER_PATH)/ft_process_single_quotes.c \
			   $(FT_LEXER_PATH)/ft_strtok.c \
			   $(FT_LEXER_PATH)/ft_tokenise.c

FT_EXPAND_SRC = $(FT_EXPAND_PATH)/ft_append_escape_sequence.c \
				$(FT_EXPAND_PATH)/ft_append_normal_sequence.c \
				$(FT_EXPAND_PATH)/ft_expand_asyntactic_names.c \
				$(FT_EXPAND_PATH)/ft_expand_cstring.c \
				$(FT_EXPAND_PATH)/ft_expand_normal_construct.c \
				$(FT_EXPAND_PATH)/ft_expand_pipeline.c \
				$(FT_EXPAND_PATH)/ft_expand_scmd.c \
				$(FT_EXPAND_PATH)/ft_expand_singlequote_construct.c \
				$(FT_EXPAND_PATH)/ft_expand_special_parameters.c \
				$(FT_EXPAND_PATH)/ft_expand_token.c \
				$(FT_EXPAND_PATH)/ft_handle_character_escape_sequence.c \
				$(FT_EXPAND_PATH)/ft_handle_control_escape_sequence.c \
				$(FT_EXPAND_PATH)/ft_handle_hex_escape_sequence.c \
				$(FT_EXPAND_PATH)/ft_handle_octal_escape_sequence.c \
				$(FT_EXPAND_PATH)/ft_identify_variable_assignments.c \
				$(FT_EXPAND_PATH)/ft_is_special_parameter.c \
				$(FT_EXPAND_PATH)/ft_iscmd_varassignable.c \
				$(FT_EXPAND_PATH)/ft_isifs.c \
				$(FT_EXPAND_PATH)/ft_isparameter_expandable.c \
				$(FT_EXPAND_PATH)/ft_manage_active_expansion.c \
				$(FT_EXPAND_PATH)/ft_manage_passive_expansion.c \
				$(FT_EXPAND_PATH)/ft_parameter_expansion.c \
				$(FT_EXPAND_PATH)/ft_quote_removal.c \
				$(FT_EXPAND_PATH)/ft_substitute_parameter.c \
				$(FT_EXPAND_PATH)/ft_traverse_ifs.c \
				$(FT_EXPAND_PATH)/ft_word_spliting.c

FT_ERROR_SRC = $(FT_ERROR_PATH)/ft_display_error_msg.c \
			   $(FT_ERROR_PATH)/ft_manage_parsing_error.c

FT_TOKEN_SRC = $(FT_TOKEN_PATH)/ft_token_addback.c \
			   $(FT_TOKEN_PATH)/ft_token_clear.c \
			   $(FT_TOKEN_PATH)/ft_token_create.c \
			   $(FT_TOKEN_PATH)/ft_token_del.c \
			   $(FT_TOKEN_PATH)/ft_token_harddel.c \
			   $(FT_TOKEN_PATH)/ft_token_print.c \
			   $(FT_TOKEN_PATH)/ft_token_print_type.c \
			   $(FT_TOKEN_PATH)/ft_token_size.c

FT_METADATA_SRC = $(FT_METADATA_PATH)/ft_get_unimetadata.c \
				  $(FT_METADATA_PATH)/ft_getquote.c \
				  $(FT_METADATA_PATH)/ft_metadata_create.c \
				  $(FT_METADATA_PATH)/ft_metadata_dup.c \
				  $(FT_METADATA_PATH)/ft_metadata_nappend.c \
				  $(FT_METADATA_PATH)/ft_metadata_ndup.c \
				  $(FT_METADATA_PATH)/ft_metadata_print.c

FT_ENVP_SRC = $(FT_ENVP_PATH)/ft_char_to_envp.c		\
			  $(FT_ENVP_PATH)/ft_envp_addback.c		\
			  $(FT_ENVP_PATH)/ft_envp_clear.c		\
			  $(FT_ENVP_PATH)/ft_envp_create.c		\
			  $(FT_ENVP_PATH)/ft_envp_del.c			\
			  $(FT_ENVP_PATH)/ft_envp_getvalue.c	\
			  $(FT_ENVP_PATH)/ft_envp_print.c		\
			  $(FT_ENVP_PATH)/ft_envp_setvalue.c	\
			  $(FT_ENVP_PATH)/ft_load_sys_envp.c

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

FT_REDIRECTION_SRC = $(FT_REDIRECTION_PATH)/ft_redirection_addback.c \
					 $(FT_REDIRECTION_PATH)/ft_redirection_clear.c \
					 $(FT_REDIRECTION_PATH)/ft_redirection_create.c \
					 $(FT_REDIRECTION_PATH)/ft_redirection_del.c \
					 $(FT_REDIRECTION_PATH)/ft_redirection_print.c

FT_SUPPORT_FUNCTIONS_SRC = $(FT_SUPPORT_FUNCTIONS_PATH)/ft_append_character.c \
						   $(FT_SUPPORT_FUNCTIONS_PATH)/ft_strichr.c \
						   $(FT_SUPPORT_FUNCTIONS_PATH)/ft_strnappend.c \
						   $(FT_SUPPORT_FUNCTIONS_PATH)/ft_traverse_spaces.c

EXECUTION_SRC =	$(EXECUTION_PATH)/_cd.c \
			$(EXECUTION_PATH)/_echo.c \
			$(EXECUTION_PATH)/_env.c \
			$(EXECUTION_PATH)/_export.c \
			$(EXECUTION_PATH)/_pwd.c \
			$(EXECUTION_PATH)/_unset.c \
			$(EXECUTION_PATH)/builtin.c \
			$(EXECUTION_PATH)/catch_child_exitstatus.c \
			$(EXECUTION_PATH)/dup_tools.c \
			$(EXECUTION_PATH)/error.c \
			$(EXECUTION_PATH)/exec_ve.c \
			$(EXECUTION_PATH)/ft_anti_leak_tools.c \
			$(EXECUTION_PATH)/ft_check_tools.c \
			$(EXECUTION_PATH)/ft_manage_signal_output.c \
			$(EXECUTION_PATH)/ft_protect_tools.c \
			$(EXECUTION_PATH)/redirections_tools.c \
			$(EXECUTION_PATH)/run_infork.c \
			$(EXECUTION_PATH)/run_normal.c \
			$(EXECUTION_PATH)/start_execution.c \
			$(EXECUTION_PATH)/tool.c

SRC = $(EXECUTION_SRC) $(FT_PARSER_SRC) $(FT_LEXER_SRC) $(FT_EXPAND_SRC) \
	  $(FT_ERROR_SRC) $(FT_PIPELINE_SRC) $(FT_SCMD_SRC) $(FT_TOKEN_SRC) \
	  $(FT_METADATA_SRC) $(FT_REDIRECTION_SRC) $(FT_ENVP_SRC) \
	  $(FT_SUPPORT_FUNCTIONS_SRC)

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g

LIBS = /Users/$(USER)/.brew/opt/readline/lib
INCLUDES = /Users/$(USER)/.brew/opt/readline/include

all: $(NAME)

$(NAME):$(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) -lreadline -L $(LIBS) -I$(INCLUDES)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES)

$(LIBFT) :
	@$(MAKE) -C libft

clean:
	@rm -rf $(OBJ)
	@$(MAKE) -C libft fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
