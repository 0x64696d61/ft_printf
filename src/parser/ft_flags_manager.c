#include "../include/ft_printf.h"

struct s_flags *init_flags(void)
{
	// set space by default.
	flag.zero = 32;
	flag.width = 0;
	flag.precision = 0;
	flag.minus = 0;
	flag.dot = 0;
	flag.conversion = 0;
	return (&flag);
}

int check_flags(struct s_flags *flag)
{
	if (flag->zero != 32 || flag->width || flag->precision || flag->precision || flag->minus || flag->dot || flag->conversion)
	{
		return (1);
	}
	return (0);
}

void print_flags(struct s_flags *flag)
{
	printf("\n******* flags ******\n");
	printf("zero: %d\n", flag->zero);
	printf("width: %d\n", flag->width);
	printf("precision: %d\n", flag->precision);
	printf("minus: %d\n", flag->minus);
	printf("dot: %d\n", flag->dot);
	printf("conversion: %d\n", flag->conversion);
	printf("******* end flags ******\n");
}
