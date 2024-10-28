# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsindres <dsindres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 13:34:02 by dsindres          #+#    #+#              #
#    Updated: 2024/09/14 14:37:40 by dsindres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

SRC = main.c parsing.c write_data.c ft_printf.c

OBJ = $(SRC:.c=.o)

CC = cc

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -c $(FLAGS) $(SRC)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -rf $(OBJ)


fclean : clean
	rm -rf $(NAME)


re : fclean all

.PHONY: all clean fclean re