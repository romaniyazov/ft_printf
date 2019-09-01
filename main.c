/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:14:33 by adavis            #+#    #+#             */
/*   Updated: 2019/09/01 17:53:18 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		len_printf;
	int		len_ft_printf;
	char 	str[] = "o: %#07o d: %d c: %c s: %s x: %#-8X\n";

	len_ft_printf = ft_printf(str, 21, 5, '0', "Kek.", 43);
	len_printf = printf(str, 21, 5, '0', "Kek.", 43);
	printf("\nft_printf: %d\n", len_ft_printf);
	printf("printf:    %d\n", len_printf);
}
