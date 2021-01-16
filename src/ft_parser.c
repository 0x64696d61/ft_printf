#include "../include/ft_printf.h"

struct s_flags *init_flags(void)
{
	flag.zero = 0;
	flag.width = 0;
	flag.precision = 0;
	flag.minus = 0;
	flag.dot = 0;
	flag.conversion = 0;
	return (&flag);
}

int check_flags(struct s_flags *flag)
{
	if (flag->zero || flag->width || flag->precision || flag->precision || flag->minus || flag->dot || flag->conversion)
	{
		return (1);
	}
	return (0);
}

void print_flags(struct s_flags *flag)
{
	printf("\n******* flags ******\n");
	printf("zero: %d\n", flag->zero);
	printf("width: %d\n", flag->width);
	printf("precision: %d\n", flag->precision);
	printf("minus: %d\n", flag->minus);
	printf("dot: %d\n", flag->dot);
	printf("conversion: %d\n", flag->conversion);
	printf("******* end flags ******\n");
}

/* 1 - c; 2 - s; 3 - p; 4 - d; 5 - i; 6 - u; 7 - x; 8 - X */
int decode_conversion(char *str)
{
	if (DEBUG)
		printf("\nDEBUG MODE: Inpit data to decode_operation: %c\n", *str);

	if (*str == 'c')
	 	return (1);
	else if (*str == 's')
		return 2;
	else if (*str == 'p')
		return 3;
	else if (*str == 'd')
		return 4;
	else if (*str == 'i' || *str == 'u')
		return 5;
	else
		return -1;
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
		printf("\nDEBUG MODE: Inpit data to line_parser: %s\n", *str);

	while(**str)
	{
		if (**str == '%')
		{
				(*str)++;
				if (**str == '%')
				{
					printf("%c", **str);
					break;
				}
				if ((**str == '-') && (ft_isdigit(**(str + 1))))
				{
					flag->minus = 1;
					(*str)++;
				}
				else if (**str == '0')
				{
					flag->zero = 1;
					(*str)++;
				}
				if (((**str == '*') || (ft_isdigit(**(str)))) && (**(str - 1) != '.'))
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
			printf("%c", **str);
			(*str)++;
		}
	}
	return (flag);
}