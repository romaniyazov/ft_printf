/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:13:17 by adavis            #+#    #+#             */
/*   Updated: 2018/12/12 16:34:28 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	num;
	unsigned int	num2;
	unsigned int	dvdr;

	if (n < 0)
	{
		ft_putchar('-');
		num = n * -1;
	}
	else
		num = n;
	num2 = num;
	dvdr = 1;
	while (num2 > 9)
	{
		dvdr *= 10;
		num2 /= 10;
	}
	while (dvdr > 0)
	{
		ft_putchar(num / dvdr % 10 + '0');
		dvdr /= 10;
	}
}
