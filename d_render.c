/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:47:32 by adavis            #+#    #+#             */
/*   Updated: 2019/08/31 21:47:46 by adavis           ###   ########.fr       */
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

int		d_spaces(int d, t_params params);

int		d_render(int d, t_params *params)
{
	if (d < 0)
		params->width--;
	if (params->space && !(d < 0))
	{
		ft_putchar(' ');
		params->width--;
	}
	if (params->width)
	{
		if (params->left)
		{
			ft_putnbr(d);
			while ((params->width--) - nbrlen(d))
				ft_putchar(' ');
		}
		else
		{
			while (params->width-- - nbrlen(d) > 0)
				ft_putchar(params->zeros ? '0' : ' ');
			ft_putnbr(d);
		}
	}
	else
		ft_putnbr(d);
	return (0);
}
