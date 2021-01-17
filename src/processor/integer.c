#include "../include/ft_printf.h"

void draw_integer(struct s_flags *flag, va_list *ap)
{
	int num;
	int offset;
	char *string;

	if (flag->width == -1)
		flag->width = va_arg(*ap, int);
	if (flag->precision == -1)
		flag->precision = va_arg(*ap, int);

	num = va_arg(*ap, int);
	string = ft_itoa(num);

	if (flag->precision > 0)
		offset = flag->width - flag->precision;
	else
		offset = flag->width - (int)ft_strlen(string);

	if ((offset  > 0) && (flag->minus == 0))
		{
			if (num < 0)
			{
				num *= -1;
				ft_putchar('-');
			}
			while(offset--)
				ft_putchar(flag->zero);
		}
	if (flag->precision > 0)
		while(flag->precision--)
			ft_putchar(*string++);
	else
		ft_putnbr(num);
	if (flag->minus == 1)
		while(offset--)
			ft_putchar(flag->zero);
}
