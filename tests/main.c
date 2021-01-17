#include "../include/ft_printf.h"

int main()
{
	char *st1 = "abcdefg";
	printf("origin printf: %40s sdfsfsdf\n", st1);
	ft_printf("ft_printf: %40s sdfsfsdf\n", st1);
}
