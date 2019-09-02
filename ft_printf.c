/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:59:48 by adavis            #+#    #+#             */
/*   Updated: 2019/09/01 14:43:56 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_params	params;
	char		*fmt;
	int			len;

	len = 0;
	va_start(ap, format);
	fmt = ft_strdup(format);
	while (*fmt)
	{
		if (*fmt == '%')
			len += parse(&fmt, ap, &params);
		else
		{
			ft_putchar(*fmt);
			len++;
		}
		fmt++;
	}
	return (len);
}
