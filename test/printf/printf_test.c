#include <stdio.h>

int main()
{
	int	a;

	printf("%%c (c): ");
	printf("%c\n", 'c');
	printf("%%c (0): ");
	printf("%c\n", -1);
	printf("\n");

	printf("%%s (abcde): ");
	printf("%s\n", "abcde");
	printf("%%s (0): ");
	printf("%s\n", 0);
	printf("\n");

	// int
	printf("%%p (&a): ");
	printf("%p\n", &a);
	printf("%%p (-1): ");
	printf("%p\n", -1);
	printf("%%p (-2): ");
	printf("%p\n", -2);
	printf("%%p (0): ");
	printf("%p\n", 0);
	printf("\n");

	// int
	printf("%%d (5): ");
	printf("%d\n", 5);
	printf("%%d (0xFFFFFFFF / 2): ");
	printf("%d\n", 0xFFFFFFFF / 2);
	printf("%%d (0x100000000 / 2): ");
	printf("%d\n", 0x100000000 / 2);
	printf("\n");

	// int
	printf("%%i (0xFFFFFFFF / 2): ");
	printf("%i\n", 0xFFFFFFFF / 2);
	printf("%%i (0x100000000 / 2): ");
	printf("%i\n", 0x100000000 / 2);
	printf("\n");

	// unsigned int
	printf("%%u: ");
	printf("%u\n", -1);
	printf("%%u (0xFFFFFFFF / 2): ");
	printf("%u\n", 0xFFFFFFFF / 2);
	printf("%%u (0xFFFFFFFF): ");
	printf("%u\n", 0xFFFFFFFF);
	printf("%%u (0x100000000): ");
	printf("%u\n", 0x100000000);
	printf("\n");

	printf("%%x (0xFFFFFFFF): ");
	printf("%x\n", 0xFFFFFFFF);
	printf("%%x (0xFFFFFFFFFFFFFFFF): ");
	printf("%x\n", 0xFFFFFFFFFFFFFFFF);
	printf("\n");

	printf("%%X (0xFFFFFFFF): ");
	printf("%X\n", 0xFFFFFFFF);
	printf("%%X (0xFFFFFFFFFFFFFFFF): ");
	printf("%X\n", 0xFFFFFFFFFFFFFFFF);
	printf("\n");

	printf("%%: ");
	printf("%%\n");


	return (0);
}