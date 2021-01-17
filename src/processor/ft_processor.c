#include "../include/ft_printf.h"

// left flags: cpdiuxX%
// do flags: i
// done flags: s
void run_processor(struct s_flags *flag, va_list *ap)
{
	if (DEBUG)
		printf("\nDEBUG MODE: Input data to run_processor\n");

	if (flag->conversion == STRING)
	{
		if (DEBUG)
			printf("This is STRING\n");
		draw_string(flag, ap);
	}

	if (flag->conversion == INTEGER)
	{
		if (DEBUG)
			printf("This is INTEGER\n");
		draw_integer(flag, ap);
	}

}
