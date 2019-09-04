/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:13:21 by adavis            #+#    #+#             */
/*   Updated: 2019/09/04 15:26:15 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_render(char *s, t_params *params)
{
	int		len;
	char	*str;

	if (s == NULL)
		s = ft_strdup("(null)");
	if (params->precision > 0)
	{
		str = ft_strnew(params->precision);
		ft_strncpy(str, s, params->precision);
		s = str;
	}
	len = (
		(int)ft_strlen(s) > (int)params->width ? ft_strlen(s) : params->width);
	if (params->left)
		ft_putstr(s);
	while ((int)(params->width--) - (int)ft_strlen(s) > 0)
		ft_putchar(' ');
	if (!params->left)
		ft_putstr(s);
	if (params->precision)
		ft_strdel(&str);
	return (len);
}
