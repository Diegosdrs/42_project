# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsindres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 14:46:18 by dsindres          #+#    #+#              #
#    Updated: 2024/05/15 17:26:32 by dsindres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

HEADER = ./ex27

FLAGS = -Wall -Wextra -Werror

SRC = ft_display_file.c

OBJ = ft_display_file.o

CC = gcc

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) $(SRC)
	mv a.out $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re 
