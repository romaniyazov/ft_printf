/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:20:03 by adavis            #+#    #+#             */
/*   Updated: 2019/08/31 21:07:18 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse(char **fmt, va_list ap, t_params *params)
{
	int		len;

	len = 0;
	set_flags(fmt, params);
	if (**fmt == 'd')
		d_render(va_arg(ap, int), params);
	return (len);
}
