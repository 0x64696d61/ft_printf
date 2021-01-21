#include "../include/ft_printf.h"

// left flags: X%
// do flags: x
// done flags: suidcp
void run_processor(struct s_flags *flag, va_list *ap)
{
	if (DEBUG)
		printf("\nDEBUG MODE: Input data to run_processor\n");
	if (DEBUG_FLAGS)
		print_flags(flag);

	if (flag->width == -1)
		flag->width = va_arg(*ap, int);
	if (flag->precision == -1)
		flag->precision = va_arg(*ap, int);

	if (flag->conversion == CHAR)
	{
		if (DEBUG)
			printf("This is CHAR\n");
		draw_char(flag, ap);
	}

	else if (flag->conversion == STRING)
	{
		if (DEBUG)
			printf("This is STRING\n");
		draw_string(flag, ap);
	}

	else if (flag->conversion == U_INTEGER)
	{
		if (DEBUG)
			printf("This is U_INTEGER\n");
		draw_u_integer(flag, ap);
	}

	else if (flag->conversion == INTEGER)
	{
		if (DEBUG)
			printf("This is INTEGER\n");
		draw_integer(flag, ap);
	}

	else if (flag->conversion == POINTER)
	{
		if (DEBUG)
			printf("This is POINTER\n");
		draw_pointer(flag, ap);
	}
	else if (flag->conversion == HEX || flag->conversion == HEX_UPPER)
	{
		if (DEBUG)
			printf("This is HEX\n");
		draw_hex(flag, ap);
	}
	else if (flag->conversion == PERCENT)
	{
		if (DEBUG)
			printf("This is PERCENT\n");
		draw_percent(flag);
	}
	else
		printf("Error\n");

}

char	*fill_line(char *string, int offset, struct s_flags flag)
{
	char	*str;
	char	*str1;

	str = malloc(sizeof(char*) * offset + 1);
	if (str == NULL)
		return (NULL);

	str[offset] = '\0';
	ft_memset(str, flag.zero, offset);

	if (flag.minus)
		str1 = ft_strjoin(string, str);
	else
		str1 = ft_strjoin(str, string);
	free(str);
	free(string);
	return (str1);
}

char	*string_builder(char *string, struct s_flags *flag)
{
	int		offset;

	if (flag->precision)
		if (((int)ft_strlen(string) > flag->precision))
			string[flag->precision] = '\0';
	if (flag->width)
	{
		if ((flag->width < 0) && ((flag->width + (int)ft_strlen(string)) < 0))
		{
			flag->minus = 1;
			offset = (flag->width + (int)ft_strlen(string)) * -1;
			string = fill_line(string, offset, *flag);
		}
		else
			if ((offset = flag->width - (int)ft_strlen(string)) > 0)
				string = fill_line(string, offset, *flag);
	}
	return (string);
}
