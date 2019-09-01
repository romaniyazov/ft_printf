/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:14:33 by adavis            #+#    #+#             */
/*   Updated: 2019/09/01 20:28:36 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		len_printf;
	int		len_ft_printf;
	char 	str[] = "p: %#p\n";
	void	*ptr;

	ptr = malloc(1);
	len_ft_printf = ft_printf(str, str);
	len_printf = printf(str, str);
	printf("\nft_printf: %d\n", len_ft_printf);
	printf("printf:    %d\n", len_printf);
}
