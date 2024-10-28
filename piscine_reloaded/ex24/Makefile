# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsindres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 09:49:04 by dsindres          #+#    #+#              #
#    Updated: 2024/05/15 14:19:58 by dsindres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ./includes

FLAGS = -Wall -Wextra -Werror

SRC = ./srcs/ft_putchar.c \
      ./srcs/ft_putstr.c \
      ./srcs/ft_strcmp.c \
      ./srcs/ft_strlen.c \
      ./srcs/ft_swap.c \

OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

CC = gcc

all : $(NAME)

$(NAME) :
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re 
