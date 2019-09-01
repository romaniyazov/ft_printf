/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:20:03 by adavis            #+#    #+#             */
/*   Updated: 2019/09/01 17:30:26 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(char **fmt, va_list ap, t_params *params)
{
	int		len;

	set_flags(fmt, params);
	if (**fmt == 'd')
		len = d_render(va_arg(ap, int), params);
	if (**fmt == 'c')
		len = c_render((char)va_arg(ap,int), params);
	if (**fmt == 's')
		len = s_render(va_arg(ap, char *), params);
	if (**fmt == 'o')
		len = o_render(va_arg(ap, unsigned int), params);
	if (**fmt == 'x' || **fmt == 'X')
		len = x_render(va_arg(ap, unsigned int), params, **fmt == 'X');
	return (len);
}
