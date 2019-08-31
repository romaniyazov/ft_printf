#include <stdio.h>
#include "ft_printf.h"

int		get_width(char *str)
{
	int		len;

	while (*str < '1' || *str > '9')
	{
		if (strchr(CONVERSIONS, *str) || strchr(MODIFIERS, *str) || *str == '.')
			return (0);
		str++;
	}
	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		len = len * 10 + (*str - '0');
		str++;
	}
	return (len);
}

int		get_precision(char *str)
{
	int		len;

	while (!(*str == '.'))
	{
		if (strchr(CONVERSIONS, *str) || strchr(MODIFIERS, *str))
			return (6);
		str++;
	}
	str++;
	if (*str == '0')
		return (0);
	len = 0;
	while (*str >= '0' && *str <= '9')
	{
		len = len * 10 + (*str - '0');
		str++;
	}
	return (len);
}

void	set_flags(char **fmt, t_params params)
{
	params.width = get_width(fmt);
	params.precision = get_precision(fmt);
	while (!strchr(CONVERSIONS, **fmt) || !strchr(MODIFIERS, **fmt))
	{
		if (**fmt == '-')
			params.left = true;
		if (**fmt == '+')
			params.sign = true;
		if (**fmt == ' ')
			params.width = params.width || 1;
		if (**fmt == '#')
			params.alternate = true;
		if (**fmt == '0')
			params.zeros = true;
		*fmt++;
	}
	printf("width: %d\n", params.width);
	printf("precision: %d\n", params.precision);
	printf("left: %d\n", params.left);
	printf("sign: %d\n", params.sign);
	printf("alternate: %d\n", params.alternate);
	printf("zeros: %d\n", params.zeros);
}

int     main(void)
{
	char		str[] = "% .0dblya";
	t_params	params;

	set_flags(str + 1, params);
}