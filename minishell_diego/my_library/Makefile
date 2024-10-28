# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artberna <artberna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 13:40:40 by artberna          #+#    #+#              #
#    Updated: 2024/10/17 14:20:06 by artberna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************
#                                    MAIN                                     *
#******************************************************************************

NAME = my_library.a
HEADER = my_library.h

#******************************************************************************
#                                 DIRECTORIES                                 *
#******************************************************************************

OBJ_DEP_DIR = obj_dep/
SRC_DIR = src/
LIBFT_DIR = libft/
PRINTF_DIR = printf/
GNL_DIR = get_next_line/

#******************************************************************************
#                       SOURCES, OBJECTS & DEPENDENCIES                       *
#******************************************************************************

LIBFT_SRC = ft_atoi ft_bzero ft_calloc ft_isalnum \
ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa \
ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset \
ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd \
ft_split ft_strchr ft_strdup ft_striteri ft_strjoin \
ft_strcat ft_strlcat ft_strcpy ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
ft_strstr ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower \
ft_toupper ft_lstadd_back ft_lstadd_front ft_lstclear \
ft_lstdelone ft_lstiter ft_lstlast ft_lstmap \
ft_lstnew ft_lstsize ft_strndup ft_realloc ft_strjoin_no_free
LIBFT_FLS = $(addprefix $(LIBFT_DIR),$(addsuffix .c, $(LIBFT_SRC)))

PRINTF_SRC = ft_printf ft_write
PRINTF_FLS = $(addprefix $(PRINTF_DIR),$(addsuffix .c, $(PRINTF_SRC)))

GNL_SRC = get_next_line_bonus
GNL_FLS = $(addprefix $(GNL_DIR),$(addsuffix .c, $(GNL_SRC)))

SRC = $(LIBFT_FLS) $(PRINTF_FLS) $(GNL_FLS)

OBJ = $(addprefix $(OBJ_DEP_DIR), $(SRC:.c=.o))

OBJF = .cache_exists

DEP = $(addprefix $(DEP_DIR), $(OBJ:.o=.d))

#******************************************************************************
#                                INSTRUCTIONS                                 *
#******************************************************************************

CC = cc
FLAGS = -Wall -Wextra -Werror -I.
RM = rm -rf
AR = ar rcs

#******************************************************************************
#                                  COLORS                                     *
#******************************************************************************

# Lien pour les couleurs en ANSI :
# https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
# Lien pour le texte en ASCII :
#https://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20

RESET = \033[0m

COLOR_10 = \033[38;5;33m
COLOR_11 = \033[38;5;69m
COLOR_12 = \033[38;5;105m
COLOR_13 = \033[38;5;141m
COLOR_14 = \033[38;5;177m
COLOR_15 = \033[38;5;213m

ROSE = \033[1;38;5;225m
VIOLET = \033[1;38;5;55m
VERT = \033[1;38;5;85m
BLEU = \033[1;34m

#******************************************************************************
#                                COMPILATION                                  *
#******************************************************************************

all : $(NAME)
	@echo "$(ROSE)COMPILATION FINISHED, FILES CREATED :"
	@echo "$(COLOR_10)███╗   ███╗██╗   ██╗    ██╗     ██╗██████╗ ██████╗  █████╗ ██████╗ ██╗   ██╗$(RESET)"
	@echo "$(COLOR_11)████╗ ████║╚██╗ ██╔╝    ██║     ██║██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝$(RESET)"
	@echo "$(COLOR_12)██╔████╔██║ ╚████╔╝     ██║     ██║██████╔╝██████╔╝███████║██████╔╝ ╚████╔╝$(RESET)"
	@echo "$(COLOR_13)██║╚██╔╝██║  ╚██╔╝      ██║     ██║██╔══██╗██╔══██╗██╔══██║██╔══██╗  ╚██╔╝$(RESET)"
	@echo "$(COLOR_14)██║ ╚═╝ ██║   ██║       ███████╗██║██████╔╝██║  ██║██║  ██║██║  ██║   ██║$(RESET)"
	@echo "$(COLOR_15)╚═╝     ╚═╝   ╚═╝       ╚══════╝╚═╝╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝$(RESET)"

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DEP_DIR)%.o: %.c $(HEADER) | $(OBJF)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -MMD -MP -c $< -o $@
	@echo "$(BLEU)Compiling $< to $@$(RESET)"

$(OBJF):
	@mkdir -p $(OBJ_DEP_DIR)

clean :
	@$(RM) $(OBJ_DEP_DIR)
	@echo "$(VIOLET)Suppressing objects & dependencies files of $(NAME)$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(VERT)Suppressing archives $(NAME)$(RESET)"

re : fclean all

-include $(DEP)

.PHONY : re fclean clean all
