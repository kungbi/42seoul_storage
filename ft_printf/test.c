#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char		*str = "abcdef";
	long long	ll = 123124521;
	int num;
	unsigned int ui = 123123;

	num = printf(" %p %p ", 4294967296, -4294967296);
	printf("num: %d\n", num);
	num = ft_printf(" %p %p ", 4294967296, -4294967296);
	printf("num: %d\n", num);
	return 0;
}