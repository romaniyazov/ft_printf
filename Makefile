# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 18:04:47 by adavis            #+#    #+#              #
#    Updated: 2019/09/04 21:02:38 by adavis           ###   ########.fr        #
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
			d_render_zeros.c \
			d_render_short.c \
			o_render.c \
			o_empty.c \
			x_render.c \
			x_empty.c \
			p_render.c \
			u_render.c \
			f_render.c \
			perc_render.c \
			ft_putnbr_base.c
OBJ		=	$(SRC:%.c=%.o)

$(NAME):
	@cd libft && make
	@gcc $(SRC) $(FLAGS) -c -Ilibft
	@cp libft/libft.a libftprintf.a
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@cd libft && make clean
	@rm -f $(OBJ)

fclean: clean
	@cd libft && make fclean
	@rm -f $(NAME)

re: fclean all
