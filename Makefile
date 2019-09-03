# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 18:04:47 by adavis            #+#    #+#              #
#    Updated: 2019/09/03 16:51:14 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FLAGS	=	-Wall -Werror -Wextra
SRC 	=	ft_printf.c \
			parse.c \
			set_flags.c \
			handlers.c \
			c_render.c \
			s_render.c \
			d_render.c \
			o_render.c \
			x_render.c \
			p_render.c \
			u_render.c \
			f_render.c \
			ft_putnbr_base.c
OBJ		=	ft_printf.o \
			parse.o \
			set_flags.o \
			handlers.o \
			c_render.o \
			s_render.o \
			d_render.o \
			o_render.o \
			x_render.o \
			p_render.o \
			u_render.o \
			f_render.o \
			ft_putnbr_base.o

$(NAME):
	gcc $(SRC) $(FLAGS) -c -Ilibft
	cp libft/libft.a libftprintf.a
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
