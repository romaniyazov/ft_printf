/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 14:26:57 by adavis            #+#    #+#             */
/*   Updated: 2019/08/30 15:01:04 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	init_params(t_params *params)
{
	(*params).alternate = false;
	(*params).width_zeros = false;
	params->width_spaces = false;
	(*params).left = false;
	(*params).sign = false;
	(*params).space = false;
	(*params).width_val = 0;
}

int		add_flag(char *flag, t_params *params)
{
	int		cnt;
	int		val;

	if (*flag == '#')
		(*params).alternate = true;
	if (*flag == '0')
	{
		(*params).width_zeros = true;
		cnt = 0;
		val = 0;
		while (*flag >= '0' && *flag <= '9')
		{
			val *= 10;
			val += *flag - '0';
			cnt++;
			flag++;
		}
		(*params).width_val = val;
		return cnt;
	}
	if (*flag == '-')
		params->left = true;
	if (*flag == '+')
		params->sign = true;
	if (*flag == ' ')
	{
		params->width_spaces = true;
		cnt = 0;
		val = 0;
		flag++;
		while (*flag >= '0' && *flag <= '9')
		{
			val *= 10;
			val += *flag - '0';
			cnt++;
			flag++;
		}
		if (cnt)
		{
			params->width_val = val;
			return cnt + 1;
		}
		else
			params->width_val = 1;
	}
	if (*flag >= '0' && *flag <= '9')
	{
		params->width_spaces = true;
		cnt = 0;
		val = 0;
		while (*flag >= '0' && *flag <= '9')
		{
			val *= 10;
			val += *flag - '0';
			cnt++;
			flag++;
		}
		if (cnt)
		{
			params->width_val = val;
			return cnt + 1;
		}
		else
			params->width_val = 1;
	}
	return 1;
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
}

void	parse_spec(char **fmt, va_list ap)
{
	int			cnt;
	t_params	params;

	init_params(&params);
	cnt = 1;
	while (ft_strchr(FLAGS, *(*fmt + cnt)))
	{
		cnt += add_flag((*fmt + cnt), &params);
	}
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

void	ft_printf(const char *format, ...)
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
}

int		main(void)
{
	char str[] = "My name is %s. I'm %-#08d y.o. %c-words?\n";

	ft_printf(str, "Adavis", -21, 'F');
	printf(str, "Adavis", -21, 'F');
}
