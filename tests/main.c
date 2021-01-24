#include "../include/ft_printf.h"

int main()
{

	// https://github.com/cacharle/ft_printf_test

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

	// int num = 33;
	// printf("or_printf: %.5u sdfsfsdf\n", num);
	// ft_printf("ft_printf: %.5u sdfsfsdf\n", num);
	//
	//
	// printf("or_printf: %05i sdfsfsdf\n", num);
	// ft_printf("ft_printf: %05i sdfsfsdf\n", num);

	// printf("or_printf: %7i sdfsfsdf\n", num);
	// ft_printf("ft_printf: %7i sdfsfsdf\n", num);



	// CHAR TESTING

	// UINTEGER TESTING

	//char x = NULL;
	// printf("or_printf: %.5u sdfsfsdf\n", num);
	// ft_printf("ft_printf: %.5u sdfsfsdf\n", num);
	//

	//printf("or_printf: %3x", 0);

	//printf("(null), , (null), (null), (null), (null), (null),");
	//printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
//	ft_printf("{%.*d}", 0, 42);
//	printf("\n");

	// printf("\norigin: %.p", NULL);
	// ft_printf("\nmy:%.p", NULL);

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

 	a = 4;
	b = 0;
	//int size1 = printf("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);

	//Test 204
	int size1 =    printf("%-113p%--84.119i%--148.*%" ,(void*)5823493674460226049lu,-1063903126,-3);
	ft_putstr("\n\n");
	int size2 = ft_printf("%-113p%--84.119i%--148.*%" ,(void*)5823493674460226049lu,-1063903126,-3);
	//printf("\n");

//^@, ^@, ^@    ,      ^@,    ^@, ^@, ^@, ^@, ^@
//^@, ^@ , ^@   ,     ^@,   ^@, ^@, ^@, ^@, ^@

	//
	// printf("\n");

	// ft_printf("%*d", -32, 22);
	// printf("\n");
	// printf("%*d", -32, 22);
	//ft_printf("ft_printf: %3x", 0);


	// printf("or_printf: %7i sdfsfsdf\n", num);
	// ft_printf("ft_printf: %7i sdfsfsdf\n", num);

}
