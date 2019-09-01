/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:47:32 by adavis            #+#    #+#             */
/*   Updated: 2019/09/01 20:27:45 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_nbrlen(unsigned long long nbr)
{
	int		cnt;

	cnt = 1;
	while (nbr /= 16)
		cnt++;
	return (cnt);
}

int		p_count_len(unsigned long long d, t_params *params)
{
	int					len;
	unsigned long long	tmp;

	tmp = d;
	len = 1;
	while (tmp /= 16)
		len++;
	if (params->width > len)
		len += params->width - len;
	return (len + 2);
}

void	p_render_left(unsigned long long d, t_params *params)
{
	if (params->alternate)
		params->width--;
	if (params->width)
	{
		if (params->alternate)
			ft_putstr("0x");
		ft_putnbr_base(d, 16, false);
		while ((params->width--) - p_nbrlen(d) > 0)
			ft_putchar(' ');
	}
	else
		ft_putnbr_base(d, 16, false);
}

void	p_render_right(unsigned long long d, t_params *params)
{
	if (params->zeros)
	{
		ft_putstr("0x");
		while ((params->width--) - p_nbrlen(d) > 0)
			ft_putchar(params->zeros ? '0' : ' ');
		ft_putnbr_base(d, 16, false);
	}
	else
	{
		while ((params->width--) - p_nbrlen(d) > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		ft_putnbr_base(d, 16, false);
	}
}

int		p_render(unsigned long long d, t_params *params)
{
	int		len;

	len = p_count_len(d, params);
	if (params->left)
		p_render_left(d, params);
	else
		p_render_right(d, params);
	return (len);
}
