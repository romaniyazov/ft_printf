/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:47:32 by adavis            #+#    #+#             */
/*   Updated: 2019/09/04 15:48:42 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	x_nbrlen(unsigned long long nbr)
{
	size_t	cnt;

	cnt = 1;
	while (nbr /= 16)
		cnt++;
	return (cnt);
}

size_t	x_count_len(unsigned long long d, t_params *params)
{
	size_t				len;
	unsigned long long	tmp;

	tmp = d;
	len = 1;
	while (tmp /= 16)
		len++;
	if (params->alternate && d > 0)
		len += 2;
	if ((int)params->width > (int)len)
		len += params->width - len;
	return (len);
}

void	x_render_left(unsigned long long d, t_params *params, t_bool upper)
{
	if (params->alternate)
		params->width -= 2;
	if (params->width)
	{
		if (params->alternate)
			ft_putstr(upper ? "0X" : "0x");
		ft_putnbr_base(d, 16, upper);
		while ((int)(params->width--) - (int)x_nbrlen(d) > 0)
			ft_putchar(' ');
	}
	else
		ft_putnbr_base(d, 16, upper);
}

void	x_render_right(unsigned long long d, t_params *params, t_bool upper)
{
	if (params->zeros)
	{
		if (params->alternate && d > 0)
			ft_putstr(upper ? "0X" : "0x");
		while ((int)(params->width--) - (int)x_nbrlen(d) -
													params->alternate * 2 > 0)
			ft_putchar(params->zeros ? '0' : ' ');
		ft_putnbr_base(d, 16, upper);
	}
	else
	{
		while ((int)(params->width--) - (int)x_nbrlen(d) -
													params->alternate * 2 > 0)
			ft_putchar(' ');
		if (params->alternate)
			ft_putstr(upper ? "0X" : "0x");
		ft_putnbr_base(d, 16, upper);
	}
}

int		x_empty(size_t width)
{
	int		i;

	i = 0;
	while (i++ < (int)width)
		ft_putchar(' ');
	return (width);
}

int		x_render(unsigned long long d, t_params *params, t_bool upper)
{
	size_t	len;

	if (params->prec && !params->precision && d == 0)
		return(x_empty(params->width));
	len = x_count_len(d, params);
	if (params->left)
		x_render_left(d, params, upper);
	else
		x_render_right(d, params, upper);
	return (len);
}
