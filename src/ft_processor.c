#include "../include/ft_printf.h"

void run_processor(struct s_flags *flag, va_list *ap)
{
	if (DEBUG)
		printf("\nDEBUG MODE: Inpit data to run_processor\n");

	if (flag->conversion == STRING)
	{
		if (DEBUG)
			printf("This is STRING\n");
		if (flag->precision == -1)
			flag->precision = va_arg(*ap, int);
		char *string = va_arg(*ap, char*);
		if (flag->precision > 0)
		{
			while(flag->precision--)
				printf("%c", *string++);
		}
		else
			printf("%s", string);	
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
				if (flag->zero)
					printf("0");
				else if (flag->zero == -1)
				{
					string = va_arg(*ap, int);
					printf("%d", string);
				}
				else
					printf(" ");
			}
		}
		string = va_arg(*ap, int);
		printf("%d", string);
	}


}
