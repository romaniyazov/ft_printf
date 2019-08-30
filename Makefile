# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 13:37:06 by adavis            #+#    #+#              #
#    Updated: 2019/08/30 15:15:13 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_printf
FLAGS		=	-Llibft -lft #-Wall -Werror -Wextra
SRC			=	main.c \
				ft_printf.c \
				print_d.c
OBJ			=	$(SRC:%.c=%.o)

$(NAME):
	@gcc $(SRC) -o $(NAME) $(FLAGS)

all: $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all
