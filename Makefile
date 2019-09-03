# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adavis <adavis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/02 18:04:47 by adavis            #+#    #+#              #
#    Updated: 2019/09/03 12:12:40 by adavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ft_printf

SRCS =	ft_printf.c \
		parse.c \
		set_flags.c \
		c_render.c \
		s_render.c \
		d_render.c \
		o_render.c \
		x_render.c \
		p_render.c \
		u_render.c \
		f_render.c \
		ft_putnbr_base.c \
		main.c

OBJ =	$(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc $(SRCS) -o $(NAME) -Llibft -lft -I libft

fclean:
	@rm -f $(NAME)

re: fclean all
