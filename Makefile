# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/03 13:37:06 by adavis            #+#    #+#              #
#    Updated: 2019/09/01 18:02:26 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_printf
FLAGS		=	-Llibft -lft #-Wall -Werror -Wextra
SRC			=	main.c \
				ft_printf_n.c \
				parse.c \
				set_flags.c \
				d_render.c \
				c_render.c \
				s_render.c \
				o_render.c \
				x_render.c \
				ft_putnbr_base.c
OBJ			=	$(SRC:%.c=%.o)

$(NAME):
	@gcc $(SRC) -o $(NAME) $(FLAGS) -c

all: $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all
