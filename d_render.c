/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:47:32 by adavis            #+#    #+#             */
/*   Updated: 2019/09/04 16:14:29 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	d_nbrlen(long long nbr)
{
	int		cnt;

	cnt = 1;
	while (nbr /= 10)
		cnt++;
	return (cnt);
}

int		d_count_len(long long d, t_params *params)
{
	size_t	len;

	len = d_nbrlen(d);
	if (d < 0 || params->sign || params->space)
		len++;
	if (params->width > len)
		len += params->width - len;
	if (params->precision > (int)params->width && params->width)
		len += params->precision - params->width;
	if (params->precision > (int)len)
		len += params->precision - (int)d_nbrlen(d);
	return (len);
}

void	d_render_left(long long d, t_params *params)
{
	if (d < 0)
		params->width--;
	if ((params->space || params->sign) && d >= 0)
	{
		ft_putchar(params->sign ? '+' : ' ');
		params->width--;
	}
	while ((int)params->precision-- - (int)d_nbrlen(d) > 0)
	{
		ft_putchar('0');
		params->width--;
	}
	if (params->width)
	{
		ft_putnbr(d);
		while ((int)(params->width--) - (int)d_nbrlen(d) > 0)
			ft_putchar(' ');
	}
	else
		ft_putnbr(d);
}

void	d_render_right(long long d, t_params *params)
{
	if (params->space && d >= 0 && !params->sign)
		ft_putchar(' ');
	if (d < 0 || (params->sign && d >= 0))
		params->width--;
	if (params->zeros)
	{
		if (d < 0)
			ft_putchar('-');
		else if (params->sign)
			ft_putchar('+');
		while ((int)(params->width--) - (int)d_nbrlen(d) - params->space > 0)
			ft_putchar('0');
		ft_putnbr(d >= 0 ? d : -d);
	}
	else
	{
		while ((int)(params->width--) - params->space - params->precision > 0)
			ft_putchar(' ');
		if (params->sign && d >= 0)
			ft_putchar('+');
		if (d < 0 && d > -9223372036854775807)
		{
			d = -d;
			ft_putchar('-');
		}
		while (params->precision-- - (int)d_nbrlen(d) > 0)
			ft_putchar('0');
		ft_putnbr(d);
	}
}

int		d_empty(size_t width)
{
	int		i;

	i = 0;
	while (i++ < (int)width)
		ft_putchar(' ');
	return (width);
}

int		d_render(long long d, t_params *params)
{
	int		len;

	if (params->prec && !params->precision && d == 0)
		return(d_empty(params->width));
	if ((int)d_nbrlen(d) > params->precision)
		params->precision = (int)d_nbrlen(d);
	len = d_count_len(d, params);
	if (params->left)
		d_render_left(d, params);
	else
		d_render_right(d, params);
	return (len);
}
