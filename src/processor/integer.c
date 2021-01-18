#include "../include/ft_printf.h"

void draw_integer(struct s_flags *flag, va_list *ap)
{
	int num;
	int offset = 0;
	char *string;

	if (flag->width == -1)
		flag->width = va_arg(*ap, int);
	if (flag->precision == -1)
		flag->precision = va_arg(*ap, int);

	num = va_arg(*ap, int);

	if (num < 0)
	{
		num *= -1;
		ft_putchar('-');
		offset = 1;
	}
	string = ft_itoa(num);

	if (flag->precision > 0)
		offset = flag->precision - (int)ft_strlen(string);
	else if (flag->width > 0)
		offset = flag->width - (int)ft_strlen(string) - offset;

	if (offset > 0)
			while(offset--)
				ft_putchar('0');

	if (flag->precision > 0)
		while(flag->precision--)
			ft_putchar(*string++);
	else
		ft_putnbr(num);
	if (flag->minus == 1)
		while(offset--)
			ft_putchar(flag->zero);
}
