# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 14:37:18 by dsindres          #+#    #+#              #
#    Updated: 2024/08/07 10:25:01 by dsindres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

FLAGS = -Wall -Wextra -Werror -g3 -I.

EXE_FLAGS = -lX11 -lXext

SRC = so_long.c  utils.c check_file_2.c check_file_3.c\
check_file_4.c game.c key_input.c display_image.c close_game.c\
check_file.c

OBJ_DIR = obj
MINILIBX = minilibx-linux
MINILIBX_FLAGS = -L./$(MINILIBX) -l:libmlx_Linux.a
LIBFT = libft
LIBFT_FLAGS = -L./$(LIBFT) -l:libft.a

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


CC = cc


all : $(NAME)

$(NAME): $(OBJ) | $(LIBFT)/libft.a $(MINILIBX)/libmlx_Linux.a
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT_FLAGS) $(MINILIBX_FLAGS) $(EXE_FLAGS) -o $(NAME)
	@echo "compilation done :)"
	
$(MINILIBX)/libmlx_Linux.a :
	@make -C $(MINILIBX)

$(LIBFT)/libft.a :
	@make -C $(LIBFT)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@
	
clean :
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT)
	@make clean -C $(MINILIBX)
	@echo "cleaned"

fclean : clean
	@rm -rf $(NAME)
	@rm -f $(LIBFT)/libft.a
	@rm -f $(MINILIBX)/libmlx_Linux.a
	@echo "fcleaned :)"


re : fclean all

.PHONY: all clean fclean re