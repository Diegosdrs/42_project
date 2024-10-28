# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/12 12:11:23 by dsindres          #+#    #+#              #
#    Updated: 2024/08/15 15:10:51 by dsindres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = philo.h

FLAGS = -Wall -Wextra -Werror -g3

SRC = main.c philosophers.c verif_arg.c utils.c routine.c routine_2.c philo_checker.c

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