#include "../include/ft_printf.h"

static char *set_minus_first(char *string)
{
	char *pos;

	if (!string)
		return (string);
	pos = ft_strchr(string, '-');
	if (pos)
	{
		*pos = '0';
		string[0] = '-';
	}
	return string;
}

char	*int_string_builder(char *string, struct s_flags *flag)
{
	int		offset;
	struct s_flags local_flag;
	local_flag = *flag;

	if (local_flag.precision)
	{
		// if (local_flag.width)
		// 	local_flag.minus = 0;
		local_flag.zero = '0';
		local_flag.minus = 0;
		if ((offset = local_flag.precision - (int)ft_strlen(string)) > 0)
			string = fill_line(string, offset, local_flag);
		local_flag = *flag;
	}
	if (local_flag.negative == -1)
		string = ft_strjoin("-", string);

		if ((flag->dot) && (flag->precision == 0) && ((string[0] == '0') &&  (string[1] == '\0')))
				string[0] = '\0';

	if (local_flag.width)
	{
		if ((local_flag.precision > 0 || local_flag.width < 0))
			local_flag.zero = ' ';
		else if (local_flag.precision < 0 && local_flag.zero == '0')
			local_flag.zero = '0';
		else if (local_flag.precision == 0 && local_flag.width > 0 && local_flag.dot)
			local_flag.zero = ' ';
		if ((flag->width < 0) && ((flag->width + (int)ft_strlen(string)) < 0))
		{
			local_flag.minus = 1;
			offset = (local_flag.width + (int)ft_strlen(string)) * -1;
			string = fill_line(string, offset, local_flag);
		}
		else
			if ((offset = flag->width - (int)ft_strlen(string)) > 0)
				string = fill_line(string, offset, local_flag);
	}

	if (local_flag.width && local_flag.negative == -1 && flag->zero == '0' && (!local_flag.precision))
		string = set_minus_first(string);
	return (string);
}

int	draw_integer(struct s_flags *flag, va_list *ap)
{
	long num;
	char *string;
	int size;

	num = (long) va_arg(*ap, int);
	if (((num < 0) && (flag->zero == '0')) || ((num < 0) && (flag->precision)) || \
						 ((num < 0) && (flag->width)))
		flag->negative = -1;

	string = ft_itoa(num * flag->negative);
	string = int_string_builder(string, flag);

	ft_putstr(string);
	size = ft_strlen(string);
	free(string);
	return (size);
}
