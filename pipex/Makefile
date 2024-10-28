# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 11:17:41 by dsindres          #+#    #+#              #
#    Updated: 2024/07/23 10:10:27 by dsindres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADER = pipex.h

FLAGS = -Wall -Wextra -Werror -g3

SRC = pipex.c utils.c ft_split.c ft_strjoin_strlen.c \
ft_strnstr.c putstr_fd.c check_command.c

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


CC = cc


all : $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "compilation done :)"

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@
	
clean :
	@rm -rf $(OBJ_DIR)
	@echo "cleaned"

fclean : clean
	@rm -rf $(NAME)
	@echo "fcleaned :)"


re : fclean all

.PHONY: all clean fclean re