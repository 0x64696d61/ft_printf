#include "../include/ft_printf.h"

void	draw_u_integer(struct s_flags *flag, va_list *ap)
{
	unsigned int num;
	char *string;

	num = va_arg(*ap, unsigned int);
	string = ft_u_itoa(num);
	string = int_string_builder(string, flag);
	ft_putstr(string);
	free(string);
}
