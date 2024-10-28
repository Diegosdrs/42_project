# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 10:02:18 by dsindres          #+#    #+#              #
#    Updated: 2024/07/11 13:35:18 by dsindres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror -g3

SRC = main.c push_swap.c imput.c init_list.c tri_push.c tri_reverse_rotate.c \
tri_rotate.c tri_swap.c ft_split.c ft_atolong.c algo_tri.c utils.c\
algo_for_3.c algo_for_5.c big_algo.c big_algo_2.c ft_printf_1.c\
ft_printf_2.c big_algo_3.c utils_2.c

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