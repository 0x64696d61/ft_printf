#include "../include/ft_printf.h"

void	draw_pointer(struct s_flags *flag, va_list *ap)
{
	unsigned long long num;
	char *string;

	num = va_arg(*ap, unsigned long long);
	if (!num)
		num = 0;
	string = string_builder(to_hex(num), flag);
	ft_putstr(string);
	free(string);
}
