/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:20:03 by adavis            #+#    #+#             */
/*   Updated: 2019/09/03 13:11:30 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_u(va_list ap, t_params *params)
{
	if (params->l == 1)
		return (u_render(va_arg(ap, unsigned long), params));
	else if (params->l == 2)
		return (u_render(va_arg(ap, unsigned long long), params));
	else
		return (u_render(va_arg(ap, unsigned int), params));
}

int		handle_d(va_list ap, t_params *params)
{
	if (params->l == 1)
		return (d_render(va_arg(ap, long), params));
	else if (params->l == 2)
		return (d_render(va_arg(ap, long long), params));
	else
		return (d_render(va_arg(ap, int), params));
}

int		handle_x(va_list ap, t_params *params, t_bool upper)
{
	if (params->l == 1)
		return (x_render(va_arg(ap, long), params, upper));
	else if (params->l == 2)
		return (x_render(va_arg(ap, long long), params, upper));
	else
		return (x_render(va_arg(ap, int), params, upper));
}

int		handle_o(va_list ap, t_params *params)
{
	if (params->l == 1)
		return (o_render(va_arg(ap, unsigned long), params));
	else if (params->l == 2)
		return (o_render(va_arg(ap, unsigned long long), params));
	else
		return (o_render(va_arg(ap, unsigned int), params));
}

int		handle_f(va_list ap, t_params *params)
{
	if (params->l == 1)
		return (f_render(va_arg(ap, double), params));
	else if (params->lll)
		return (f_render(va_arg(ap, long double), params));
	else
		return (f_render(va_arg(ap, double), params));
}

int		parse(char **fmt, va_list ap, t_params *params)
{
	int		len;

	set_flags(fmt, params);
	if (**fmt == 'd' || **fmt == 'i')
		len = handle_d(ap, params);
	if (**fmt == 'c')
		len = c_render((char)va_arg(ap,int), params);
	if (**fmt == 's')
		len = s_render(va_arg(ap, char *), params);
	if (**fmt == 'o')
		len = handle_o(ap, params);
	if (**fmt == 'x' || **fmt == 'X')
		len = handle_x(ap, params, **fmt == 'X');
	if (**fmt == 'p')
		len = p_render(va_arg(ap, unsigned long long), params);
	if (**fmt == 'u')
		len = handle_u(ap, params);
	if (**fmt == 'f')
		len = handle_f(ap, params);
	return (len);
}
