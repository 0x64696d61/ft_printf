#include "../include/ft_printf.h"

int	draw_pointer(struct s_flags *flag, va_list *ap)
{
	unsigned long long num;
	char *string;

	num = va_arg(*ap, unsigned long long);
	if (!num)
	{
		num = 0;
		if (flag->dot && flag->precision ==0)
			flag->precision = 2;
	}
	string = string_builder(to_hex(num), flag);
	ft_putstr(string);
	free(string);
	return (ft_strlen(string));
}
