/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:12:24 by adavis            #+#    #+#             */
/*   Updated: 2019/08/31 21:46:39 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	set_flags(char **fmt, t_params *params)
{
	init_params(params);
	params->width = get_width(*fmt);
	params->precision = get_precision(*fmt);
	while (!strchr(CONVERSIONS, **fmt) && !strchr(MODIFIERS, **fmt))
	{
		if (**fmt == '-')
			params->left = true;
		if (**fmt == '+')
			params->sign = true;
		if (**fmt == ' ')
			params->space = true;
		if (**fmt == '#')
			params->alternate = true;
		if (**fmt == '0' && (*(*fmt - 1) > '9' || *(*fmt - 1) < '0'))
			params->zeros = true;
		(*fmt)++;
	}
	//printf("(%d %d %d %d %d %d)", params->width, params->precision, params->left, params->sign, params->alternate, params->zeros);
	//fflush(stdout);
}
