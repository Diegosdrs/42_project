# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artberna <artberna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 13:40:40 by artberna          #+#    #+#              #
#    Updated: 2024/10/25 16:15:22 by artberna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************
#                                    MAIN                                     *
#******************************************************************************

NAME = minishell
HEADER = minishell.h

#******************************************************************************
#                                 DIRECTORIES                                 *
#******************************************************************************

OBJ_DEP_DIR = obj_dep/
MY_LIBRARY = my_library
BUILTIN_DIR = builtin/
EXEC_DIR = exec/
LEXING_DIR = lexing/
PARSING_DIR = parsing/
SIGNAL_DIR = signal/
ALL_DIR = $(OBJ_DEP_DIR) $(OBJ_DEP_DIR)$(BUILTIN_DIR) \
$(OBJ_DEP_DIR)$(EXEC_DIR) $(OBJ_DEP_DIR)$(LEXING_DIR) \
$(OBJ_DEP_DIR)$(PARSING_DIR) $(OBJ_DEP_DIR)$(SIGNAL_DIR)

#******************************************************************************
#                       SOURCES, OBJECTS & DEPENDENCIES                       *
#******************************************************************************

MINISHELL_SRC = main

BUILTIN_SRC = builtins_cd builtins_cd_2 builtins_exit builtins_export \
builtins_fonctions builtins_unset builtins_export_2 builtins_export_3

EXEC_SRC = change_redirection_utils change_redirection execution \
minishell_exec minishell_exec_2 utils_exec utils_exec_2 manage_heredoc \
manage_heredoc_2

LEXING_SRC = handle_error lexer_handler lexer_utils lexer

PARSING_SRC = handle_dollar handle_redir parser_handler \
parser_utils parser_utils_II parser

SIGNAL_SRC = handle_signal handle_exit_code

MINISHELL_FLS = $(addsuffix .c, $(MINISHELL_SRC))

BUILTIN_FLS = $(addprefix $(BUILTIN_DIR), $(addsuffix .c, $(BUILTIN_SRC)))

EXEC_FLS = $(addprefix $(EXEC_DIR), $(addsuffix .c, $(EXEC_SRC)))

LEXING_FLS = $(addprefix $(LEXING_DIR), $(addsuffix .c, $(LEXING_SRC)))

PARSING_FLS = $(addprefix $(PARSING_DIR), $(addsuffix .c, $(PARSING_SRC)))

SIGNAL_FLS = $(addprefix $(SIGNAL_DIR), $(addsuffix .c, $(SIGNAL_SRC)))

SRC = $(MINISHELL_FLS) $(BUILTIN_FLS) $(EXEC_FLS) $(LEXING_FLS) $(PARSING_FLS) $(SIGNAL_FLS)

OBJ = $(addprefix $(OBJ_DEP_DIR), $(SRC:.c=.o))

OBJF = .cache_exists

DEP = $(addprefix $(OBJ_DEP_DIR), $(OBJ:.o=.d))

#******************************************************************************
#                                INSTRUCTIONS                                 *
#******************************************************************************

CC = cc
SPECIAL_FLAGS = -lreadline
FLAGS = -Wall -Wextra -Werror -I. -g3
RM = rm -rf
AR = ar rcs
LIB_FLAGS = -L./$(MY_LIBRARY) -l:my_library.a

#******************************************************************************
#                                  COLORS                                     *
#******************************************************************************

RESET = \033[0m
ROSE = \033[1;38;5;225m
VIOLET = \033[1;38;5;55m
VERT = \033[1;38;5;85m
BLEU = \033[1;34m

#******************************************************************************
#                                COMPILATION                                  *
#******************************************************************************

all : $(NAME)
	@echo "$(ROSE)COMPILATION FINISHED, $(NAME) IS CREATED!$(RESET)"

$(NAME) : $(OBJ) | $(MY_LIBRARY)/my_library.a
	@$(CC) $(FLAGS) $(OBJ) $(LIB_FLAGS) $(SPECIAL_FLAGS) -o $(NAME)

$(MY_LIBRARY)/my_library.a :
	@make -C $(MY_LIBRARY)

$(OBJ_DEP_DIR)%.o: %.c $(HEADER) | $(OBJF)
	@$(CC) $(FLAGS) -MMD -MP -c $< -o $@
	@echo "$(BLEU)Compiling $< to $@$(RESET)"

$(OBJF):
	@mkdir -p $(ALL_DIR)

clean :
	@$(RM) $(OBJ_DEP_DIR)
	@make clean -C $(MY_LIBRARY)
	@echo "$(VIOLET)Suppressing objects & dependencies files of $(NAME)$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@rm -f $(MY_LIBRARY)/my_library.a
	@echo "$(VERT)Suppressing archives $(MY_LIBRARY).a$(RESET)"
	@echo "$(VERT)Suppressing archives $(NAME)$(RESET)"

re : fclean all

-include $(DEP)

.PHONY : re fclean clean all
