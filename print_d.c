/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 14:20:29 by adavis            #+#    #+#             */
/*   Updated: 2019/08/30 14:49:02 by adavis           ###   ########.fr       */
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

void	print_xo(int nbr, int base, t_bool upper, t_bool alternate)
{
	int		div;

	if (alternate)
	{
		if (base == 16)
			ft_putstr(upper ? "0X" : "0x");
		if (base == 8)
			ft_putchar('o');
	}
	div = base;
	while (div < nbr)
		div *= base;
	div /= base;
	while (div)
	{
		ft_putchar(BASE_CHARS_UPPER[nbr / div % base]);
		div /= base;
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