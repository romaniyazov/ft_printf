/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:14:33 by adavis            #+#    #+#             */
/*   Updated: 2019/08/30 15:15:52 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char str[] = "My name is %s. I'm %-#08d y.o. %c-words?\n";

	ft_printf(str, "Adavis", -21, 'F');
	printf(str, "Adavis", -21, 'F');
}
