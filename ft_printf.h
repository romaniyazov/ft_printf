/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:51:45 by adavis            #+#    #+#             */
/*   Updated: 2019/08/30 15:13:58 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define FLAGS "#0-+ ."
# define MODIFIERS "hlL"
# define CONVERSIONS "cspdiouxXf"
# define BASE_CHARS_UPPER "0123456789ABCDEF"
# define BASE_CHARS_LOWER "0123456789abcdef"

typedef	int		t_bool;
enum {false, true};

typedef struct	s_params
{
	t_bool		alternate;
	t_bool		left;
	t_bool		sign;
	t_bool		space;
	t_bool		prec;
	t_bool		width_zeros;
	t_bool		width_spaces;
	int			width_val;
	int			prec_val;
}				t_params;

void			parse_spec(char **fmt, va_list ap);
int				ft_printf(const char *format, ...);
void			print_d(int d, t_params params);
void			print_xo(int nbr, int base, t_bool upper, t_bool alternate);

#endif
