/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:36:17 by adavis            #+#    #+#             */
/*   Updated: 2019/09/02 21:10:50 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		f_nbrlen(int nbr)
{
	int		cnt;

	cnt = 1;
	while (nbr /= 10)
	{
		cnt++;
	}
	return (cnt);
}

size_t	f_after(long double f, t_params *params)
{
	unsigned long	mltp;
	size_t			len;
	char			c;

	len = 0;
	mltp = 10;
	while (params->precision--)
	{
		c = (long)(f * mltp) % 10 + '0';
		if ((long)(f * mltp * 10) % 10 >= 5 && !params->precision)
		{
			if (c == '9')
				c = '0';
			else
				c += 1;
		}
		ft_putchar(c);
		len++;
		mltp *= 10;
	}
	return (len);
}

size_t	f_render(long double f, t_params *params)
{
	size_t			len;

	len = f_nbrlen((int)f) + 1;
	if ((params->sign && f >= 0) || params->space)
	{
		ft_putchar(params->sign && f >= 0 ? '+' : ' ');
		len++;
	}
	if (f < 0)
	{
		f = -f;
		ft_putchar('-');
		len++;
	}
	ft_putnbr((long)f);
	ft_putchar('.');
	len += f_after(f, params);
	return (len);
}
