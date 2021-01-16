#include "../include/ft_printf.h"

int main()
{
	char *st1 = "bla bla1";
	printf("origin printf: %s\n", st1);
	ft_printf("ft_printf: %s\n", st1);
}
