/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:13:21 by adavis            #+#    #+#             */
/*   Updated: 2019/09/01 17:14:39 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_render(char *s, t_params *params)
{
	int		len;

	len = (ft_strlen(s) > params->width ? ft_strlen(s) : params->width);
	if (params->left)
		ft_putstr(s);
	while ((long long)((params->width--) - ft_strlen(s)) > 0)
		ft_putchar(' ');
	if (!params->left)
		ft_putstr(s);
	return (len);
}
