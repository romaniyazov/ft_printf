# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 18:04:47 by adavis            #+#    #+#              #
#    Updated: 2019/09/05 21:47:19 by adavis           ###   ########.fr        #
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
	@make -C libft
	@gcc $(SRC) $(FLAGS) -c -Ilibft -g
	@cp libft/libft.a libftprintf.a
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@make -C libft $@
	@rm -f $(OBJ)

fclean: clean
	@make -C libft $@
	@rm -f $(NAME)

re: fclean all
