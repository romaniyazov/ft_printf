/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:20:03 by adavis            #+#    #+#             */
/*   Updated: 2019/09/02 21:42:22 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(char **fmt, va_list ap, t_params *params)
{
	int		len;

	set_flags(fmt, params);
	if (**fmt == 'd' || **fmt == 'i')
		len = d_render(va_arg(ap, int), params);
	if (**fmt == 'c')
		len = c_render((char)va_arg(ap,int), params);
	if (**fmt == 's')
		len = s_render(va_arg(ap, char *), params);
	if (**fmt == 'o')
		len = o_render(va_arg(ap, unsigned long), params);
	if (**fmt == 'x' || **fmt == 'X')
		len = x_render(va_arg(ap, unsigned long), params, **fmt == 'X');
	if (**fmt == 'p')
		len = p_render(va_arg(ap, unsigned long long), params);
	if (**fmt == 'u')
		len = u_render(va_arg(ap, unsigned long long), params);
	if (**fmt == 'f')
		len = f_render(
			params->lll ? va_arg(ap, long double) : va_arg(ap, double), params);
	return (len);
}
