/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:14:33 by adavis            #+#    #+#             */
/*   Updated: 2019/09/03 14:39:12 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int		len_printf;
	int		len_ft_printf;
	char	str[] = "a%%%%%%3.7f\n";
	char	*ptr;

	ptr = malloc(1);
	len_ft_printf = ft_printf(str, 1234567.198756423);
	len_printf = 	   printf(str, 1234567.198756423);
	printf("\nft_printf: %d\n", len_ft_printf);
	printf("printf:    %d\n", len_printf);
}
