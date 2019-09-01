/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:46:56 by adavis            #+#    #+#             */
/*   Updated: 2019/09/01 17:34:43 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, int base, t_bool upper)
{
	unsigned int	num2;
	unsigned int	div;

	num2 = nbr;
	div = 1;
	while (num2 > 9)
	{
		div *= base;
		num2 /= base;
	}
	while (div > 0)
	{
		if (upper)
			ft_putchar(BASE_CHARS_UPPER[nbr / div % base]);
		else
			ft_putchar(BASE_CHARS_LOWER[nbr / div % base]);
		div /= base;
	}
}
