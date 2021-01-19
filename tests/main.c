#include "../include/ft_printf.h"

int main()
{

	// STRING TESTING

	// char *st1 = "hello";
	//char *st1 = NULL;
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

	//printf("or_printf: %.7s sdfsfsdf\n", st1);
	//ft_printf("ft_printf: %.7s sdfsfsdf\n", st1);

	// printf("or_printf: %.s", st1);
	// printf("\n");
	// ft_printf("ft_printf: %.s", st1);

	// INTEGER TESTING

	// int num = -99;
	// printf("or_printf: %015d10 sdfsfsdf\n", num);
	// ft_printf("ft_printf: %015d10 sdfsfsdf\n", num);
	//
	//
	// printf("or_printf: %9.5dTT sdfsfsdf\n", num);
	// ft_printf("ft_printf: %9.5dTT sdfsfsdf\n", num);


	// UINTEGER TESTING

	int num = -33;
	// printf("or_printf: %.5u sdfsfsdf\n", num);
	// ft_printf("ft_printf: %.5u sdfsfsdf\n", num);
	//

	printf("or_printf: %08.5i sdfsfsdf\n", num);
	ft_printf("ft_printf: %08.5i sdfsfsdf\n", num);

}
