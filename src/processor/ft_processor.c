#include "../include/ft_printf.h"

// left flags: pxX%
// do flags: c
// done flags: suid
void run_processor(struct s_flags *flag, va_list *ap)
{
	if (DEBUG)
		printf("\nDEBUG MODE: Input data to run_processor\n");
	if (DEBUG_FLAGS)
		print_flags(flag);

	if (flag->width == -1)
		flag->width = va_arg(*ap, int);
	if (flag->precision == -1)
		flag->precision = va_arg(*ap, int);

	if (flag->conversion == CHAR)
	{
		if (DEBUG)
			printf("This is STRING\n");
		draw_char(flag, ap);
	}

	if (flag->conversion == STRING)
	{
		if (DEBUG)
			printf("This is STRING\n");
		draw_string(flag, ap);
	}

	if (flag->conversion == U_INTEGER)
	{
		if (DEBUG)
			printf("This is U_INTEGER\n");
		draw_u_integer(flag, ap);
	}

	if (flag->conversion == INTEGER)
	{
		if (DEBUG)
			printf("This is INTEGER\n");
		draw_integer(flag, ap);
	}

}
