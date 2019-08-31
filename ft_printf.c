/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:26:57 by adavis            #+#    #+#             */
/*   Updated: 2019/08/31 19:25:16 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	init_params(t_params *params)
{
	params->alternate = false;
	params->left = false;
	params->sign = false;
	params->space = false;
	params->prec = false;
	params->zeros = false;
	params->width = 0;
	params->precision = 6;
}

int		get_width(char *str)
{
	int		len;

	while (*str < '1' || *str > '9')
	{
		if (strchr(CONVERSIONS, *str) || strchr(MODIFIERS, *str) || *str == '.')
			return (0);
		str++;
	}
	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		len = len * 10 + (*str - '0');
		str++;
	}
	return (len);
}

int		get_precision(char *str)
{
	int		len;

	while (!(*str == '.'))
	{
		if (strchr(CONVERSIONS, *str) || strchr(MODIFIERS, *str))
			return (6);
		str++;
	}
	str++;
	if (*str == '0')
		return (0);
	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		len = len * 10 + (*str - '0');
		str++;
	}
	return (len);
}

char	*set_flags(char *str, t_params *params)
{
	params->width = get_width(str);
	params->precision = get_precision(str);
	while (!strchr(CONVERSIONS, *str) || !strchr(MODIFIERS, *str))
	{
		if (*str == '-')
			params->left = true;
		if (*str == '+')
			params->sign = true;
		if (*str == ' ')
			params->width = params->width || 1;
		if (*str == '#')
			params->alternate = true;
		if (*str == '0')
			params->zeros = true;
		str++;
	}
	printf("width: %d\n", params->width);
	printf("precision: %d\n", params->precision);
	printf("left: %d\n", params->left);
	printf("sign: %d\n", params->sign);
	printf("alternate: %d\n", params->alternate);
	printf("zeros: %d\n", params->zeros);
	return (str);
}

void	conv_method(char conv, va_list ap, t_params params)
{
	if (conv == 's')
	{
		ft_putstr(va_arg(ap, char *));
	}
	if (conv == 'c')
		ft_putchar((char)va_arg(ap, int));
	if (conv == 'd')
		print_d(va_arg(ap, int), params);
	if (conv == 'x' || conv == 'X')
		print_xo(va_arg(ap, int), 16, conv == 'X', params);
	if (conv == 'o')
		print_xo(va_arg(ap, int), 8, false, params);
}

void	parse_spec(char **fmt, va_list ap)
{
	int			cnt;
	t_params	params;

	init_params(&params);
	cnt = 1;
	*fmt = set_flags(*fmt, &params);
	while (ft_strchr(MODIFIERS, *(*fmt + cnt)))
	{
		ft_printf("Modifier!");
		cnt++;
	}
	if (ft_strchr(CONVERSIONS, *(*fmt + cnt)))
	{
		conv_method(*(*fmt + cnt), ap, params);
		cnt++;
	}
	*fmt += cnt - 1;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*fmt;

	va_start(ap, format);
	fmt = (char *)format;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			parse_spec(&(fmt), ap);
		}
		else
			ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (0);
}
