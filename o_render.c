/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:47:32 by adavis            #+#    #+#             */
/*   Updated: 2019/09/01 17:36:10 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		o_nbrlen(int nbr)
{
	int		cnt;

	cnt = 1;
	while (nbr /= 8)
		cnt++;
	return (cnt);
}

int		o_count_len(int d, t_params *params)
{
	int		len;
	int		tmp;

	tmp = d;
	len = 1;
	while (tmp /= 8)
		len++;
	if (params->alternate)
		len++;
	if (params->width > len)
		len += params->width - len;
	return (len);
}

void	o_render_left(int d, t_params *params)
{
	if (params->alternate)
		params->width--;
	if (params->width)
	{
		if (params->alternate)
			ft_putchar('0');
		ft_putnbr_base(d, 8, false);
		while ((params->width--) - o_nbrlen(d) > 0)
			ft_putchar(' ');
	}
	else
		ft_putnbr_base(d, 8, false);
}

void	o_render_right(int d, t_params *params)
{
	if (params->zeros)
	{
		while ((params->width--) - o_nbrlen(d) > 0)
			ft_putchar('0');
		ft_putnbr_base(d, 8, false);
	}
	else
	{
		while ((params->width--) - o_nbrlen(d) - params->alternate > 0)
			ft_putchar(' ');
		if (params->alternate)
			ft_putchar('0');
		ft_putnbr_base(d, 8, false);
	}
}

int		o_render(int d, t_params *params)
{
	int		len;

	len = o_count_len(d, params);
	if (params->left)
		o_render_left(d, params);
	else
		o_render_right(d, params);
	return (len);
}
