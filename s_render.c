/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavis <adavis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:13:21 by adavis            #+#    #+#             */
/*   Updated: 2019/09/05 22:01:04 by adavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_render(char *s, t_params *params)
{
	int		len;
	char	*str;
	t_bool	f;

	f = false;
	if (s == NULL)
	{
		s = ft_strdup("(null)");
		f = true;
	}
	if (params->prec && ft_strlen(s))
	{
		str = ft_strnew(params->precision + 1);
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
	if (params->prec)
		ft_strdel(&str);
	if (f)
		ft_strdel(&s);
	return (len);
}
