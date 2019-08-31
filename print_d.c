/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:20:29 by adavis            #+#    #+#             */
/*   Updated: 2019/08/30 17:58:30 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nbrlen(int nbr)
{
	int		cnt;

	cnt = 1;
	while (nbr /= 10)
		cnt++;
	return (cnt);
}

int		ft_itoa_base(int nbr, int base, t_bool print)
{
	int		div;
	int		len;

	div = base;
	while (div < nbr)
		div *= base;
	div /= base;
	len = 0;
	while (div)
	{
		if (print)
			ft_putchar(BASE_CHARS_UPPER[nbr / div % base]);
		div /= base;
		len++;
	}
	return (len);
}

int		put_alternate(int base, t_bool upper)
{
	if (base == 16)
		ft_putstr(upper ? "0X" : "0x");
	if (base == 8)
		ft_putchar('0');
	return (base == 8 ? 1 : 2);
}

void	print_xo(int nbr, int base, t_bool upper, t_params params)
{
	nbr = (nbr > 0) ? nbr : -nbr;
	if (params.left)
	{
		if (params.alternate)
			put_alternate(base, upper);
		ft_itoa_base(nbr, base, true);
	}
	if (params.alternate)
		params.width_val -= base / 8;
	if (params.width_val)
	{
		if (nbr < 0)
			nbr = -nbr;
		if (params.width_zeros && !params.left && params.alternate)
			put_alternate(base, upper);
		while ((params.width_val--) - ft_itoa_base(nbr, base, false) > 0)
			ft_putchar(params.width_spaces || params.left ? ' ' : '0');
	}
	if (params.sign && nbr >= 0)
		ft_putstr("+");
	if (!params.left)
	{
		if (!params.width_zeros && params.alternate)
			put_alternate(base, upper);
		ft_itoa_base(nbr, base, true);
	}
}

void	print_d(int d, t_params params)
{
	if (params.left)
	{
		if (params.width_spaces && d >= 0)
		{
			ft_putchar(' ');
			params.width_val--;
		}
		ft_putnbr(d);
	}
	if (params.width_val)
	{
		if (d < 0)
		{
			if (params.width_zeros && !params.left)
			{
				d = -d;
				ft_putchar('-');
			}
			params.width_val--;
		}
		while ((params.width_val--) - nbrlen(d))
			ft_putchar(params.width_spaces || params.left ? ' ' : '0');
	}
	if (params.sign && d >= 0)
		ft_putstr("+");
	if (!params.left)
		ft_putnbr(d);
}