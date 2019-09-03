/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:59:48 by adavis            #+#    #+#             */
/*   Updated: 2019/09/03 19:47:55 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	va_end(ap);
	return (len);
}
