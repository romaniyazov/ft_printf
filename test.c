#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	float	pi = 1.5217391304;
	int		afterdot;
	int		i = 10;

	printf("%d.", (int)pi);
	pi = pi - (int)pi;
	printf("%lld\n", (long long)(pi * 10000000));
	printf("%.7f\n", 1.5217391304);
}