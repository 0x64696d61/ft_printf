#include "../include/ft_printf.h"

void run_processor(struct s_flags *flag, va_list *ap)
{
	int offset;
	char symb;

	if (DEBUG)
		printf("\nDEBUG MODE: Inpit data to run_processor\n");

	symb = (flag->zero) ? '0' : ' ';

	if (flag->conversion == STRING)
	{
		if (DEBUG)
			printf("This is STRING\n");
		if (flag->width == -1)
			flag->width = va_arg(*ap, int);
		if (flag->precision == -1)
			flag->precision = va_arg(*ap, int);

		char *string = va_arg(*ap, char*);
		if ((offset = flag->width - (int)ft_strlen(string)) > 0)
			while(offset--)
				ft_putchar(symb);
		if (flag->precision > 0)
		{
			while(flag->precision--)
				ft_putchar(*string++);
		}
		else
			ft_putstr(string);


	}
	if (flag->conversion == INTEGER)
	{
		// TODO: unite width and number count
		int string;

		if (DEBUG)
			printf("This is INTEGER\n");
		if (flag->width)
		{
			while(--flag->width)
			{
				if (flag->zero == -1)
				{
					string = va_arg(*ap, int);
					printf("%d", string);
				}
				else
					printf("%c", symb);
			}
		}
		string = va_arg(*ap, int);
		printf("%d", string);
	}


}
