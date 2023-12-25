#include <stdio.h>
#include "ft_printf.h"

int main()
{
	char		*str = "abcdef";
	long long	ll = 123124521;
	int num;
	unsigned int ui = 123123;

	num = printf("| %c %c %c |\n", '0', 0, '1');
	printf("num: %d\n", num);
	num = ft_printf("| %c %c %c |\n", '0', 0, '1');
	printf("num: %d\n", num);
	return 0;
}