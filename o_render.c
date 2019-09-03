/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:47:32 by adavis            #+#    #+#             */
/*   Updated: 2019/09/03 13:00:18 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	o_nbrlen(long long nbr)
{
	size_t		cnt;

	cnt = 1;
	while (nbr /= 8)
		cnt++;
	return (cnt);
}

size_t	o_count_len(long long o, t_params *params)
{
	size_t		len;
	long long	tmp;

	tmp = o;
	len = 1;
	while (tmp /= 8)
		len++;
	if (params->alternate)
		len++;
	if (params->width > len)
		len += params->width - len;
	return (len);
}

void	o_render_left(long long o, t_params *params)
{
	if (params->alternate)
		params->width--;
	if (params->width)
	{
		if (params->alternate)
			ft_putchar('0');
		ft_putnbr_base(o, 8, false);
		while ((int)(params->width--) - (int)o_nbrlen(o) > 0)
			ft_putchar(' ');
	}
	else
		ft_putnbr_base(o, 8, false);
}

void	o_render_right(long long o, t_params *params)
{
	if (params->zeros)
	{
		while ((int)(params->width--) - (int)o_nbrlen(o) > 0)
			ft_putchar('0');
		ft_putnbr_base(o, 8, false);
	}
	else
	{
		while ((int)(params->width--) - (int)o_nbrlen(o) - params->alternate > 0)
			ft_putchar(' ');
		if (params->alternate)
			ft_putchar('0');
		ft_putnbr_base(o, 8, false);
	}
}

int		o_render(long long o, t_params *params)
{
	size_t	len;

	len = o_count_len(o, params);
	if (o < 0)
	{
		ft_putchar('1');
		len += 1;
	}
	if (params->left)
		o_render_left(o, params);
	else
		o_render_right(o, params);
	return (len);
}
