/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:47:32 by adavis            #+#    #+#             */
/*   Updated: 2019/09/03 12:47:52 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	x_nbrlen(long long nbr)
{
	size_t	cnt;

	cnt = 1;
	while (nbr /= 16)
		cnt++;
	return (cnt);
}

size_t	x_count_len(long long d, t_params *params)
{
	size_t	len;
	int		tmp;

	tmp = d;
	len = 1;
	while (tmp /= 16)
		len++;
	if (params->alternate)
		len += 2;
	if ((int)params->width > len)
		len += params->width - len;
	return (len);
}

void	x_render_left(long long d, t_params *params, t_bool upper)
{
	if (params->alternate)
		params->width--;
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

void	x_render_right(long long d, t_params *params, t_bool upper)
{
	if (params->zeros)
	{
		if (params->alternate)
			ft_putstr(upper ? "0X" : "0x");
		while ((int)(params->width--) - (int)x_nbrlen(d) - params->alternate * 2 > 0)
			ft_putchar(params->zeros ? '0' : ' ');
		ft_putnbr_base(d, 16, upper);
	}
	else
	{
		while ((int)(params->width--) - (int)x_nbrlen(d) - params->alternate * 2 > 0)
			ft_putchar(' ');
		if (params->alternate)
			ft_putstr(upper ? "0X" : "0x");
		ft_putnbr_base(d, 16, upper);
	}
}

int		x_render(long long d, t_params *params, t_bool upper)
{
	size_t	len;

	len = x_count_len(d, params);
	if (params->left)
		x_render_left(d, params, upper);
	else
		x_render_right(d, params, upper);
	return (len);
}
