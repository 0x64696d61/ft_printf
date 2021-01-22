#include "../include/ft_printf.h"

/* 1 - c; 2 - s; 3 - p; 4 - d; 5 - i; 6 - u; 7 - x; 8 - X */
int decode_conversion(char *str)
{
	if (DEBUG)
		printf("\nDEBUG MODE: Input data to decode_operation: %c\n", *str);

	if (*str == 'c')
	 	return (CHAR);
	else if (*str == 's')
		return (STRING);
	else if (*str == 'p')
		return (POINTER);
	else if (*str == 'u')
		return (U_INTEGER);
	else if (*str == 'i' || *str == 'd')
		return (INTEGER);
	else if (*str == 'x')
		return (HEX);
	else if (*str == 'X')
		return (HEX_UPPER);
	else if (*str == '%')
		return (PERCENT);
	else
	{
		//ft_putstr("write code...\n");
		return -1;
	}
}
/*
	-
	0
	.
	*
	width
*/


struct s_flags *line_parser(char **str, struct s_flags *flag)
{
	if (DEBUG)
		printf("\nDEBUG MODE: Input data to line_parser: %s\n", *str);

	while(**str)
	{
		if (**str == '%')
		{
				(*str)++;
				while(**str == ' ')
				{
					ft_putchar(' ');
					(*str)++;
				}
				if (**str == '%')
				{
					ft_putchar(**str);
					break;
				}
				if (**str == '-')
				{
					while(**str == '-')
						(*str)++;
					flag->minus = 1;
				}
				else if (**str == '0')
				{
					flag->zero = 48;
					(*str)++;
					if (**str == '-')
					{
						flag->minus = 1;
						(*str)++;
					}
				}
				if (((**str == '*') || (ft_isdigit(**(str)))) && (*((*str) - 1) != '.'))
				{

					if (**str == '*')
					{
						flag->width = -1;
						(*str)++;
					}
					else
					{
						flag->width = ft_atoi(*str);
						while(ft_isdigit(**str))
							(*str)++;
					}
				}
				if (**str == '.')
				{
					flag->dot = 1;
					(*str)++;
					if (**str == '*')
					{
						flag->precision = -1;
						(*str)++;
					}
					else if (ft_isdigit(**(str)))
					{
						flag->precision = ft_atoi(*str);
						while(ft_isdigit(**str))
							(*str)++;
					}
				}
				flag->conversion = decode_conversion(*str);
				if (DEBUG)
					print_flags(flag);
				break;
		}
		else
		{
			ft_putchar(**str);
			(*str)++;
		}
	}
	return (flag);
}
