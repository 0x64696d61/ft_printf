#include "../include/ft_printf.h"

int main()
{

	// STRING TESTING

	// char *st1 = "abcdefg";
	// printf("or_printf: %40s sdfsfsdf\n", st1);
	// ft_printf("ft_printf: %40s sdfsfsdf\n", st1);
	//
	// printf("or_printf: %040s sdfsfsdf\n", st1);
	// ft_printf("ft_printf: %040s sdfsfsdf\n", st1);
	//
	// printf("or_printf: %-40s sdfsfsdf\n", st1);
	// ft_printf("ft_printf: %-40s sdfsfsdf\n", st1);
	//
	// printf("or_printf: %40.5s sdfsfsdf\n", st1);
	// ft_printf("ft_printf: %40.5s sdfsfsdf\n", st1);


	// INTEGER TESTING

	int num = -99;
	printf("or_printf: %015d10 sdfsfsdf\n", num);
	ft_printf("ft_printf: %015d10 sdfsfsdf\n", num);

}
