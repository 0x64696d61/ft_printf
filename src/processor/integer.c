#include "../include/ft_printf.h"

static	char	*fill_line(char *string, int offset, struct s_flags flag)
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

static	char	*string_builder(char *string, struct s_flags *flag)
{
	int		offset;
	struct s_flags local_flag;
	local_flag = *flag;

	if (local_flag.precision)
	{
		if (local_flag.width)
			local_flag.minus = 0;
		local_flag.zero = '0';
		if ((offset = local_flag.precision - (int)ft_strlen(string)) > 0)
			string = fill_line(string, offset, local_flag);
		local_flag = *flag;
	}
	if ((flag->dot) && (!flag->precision))
		string[0] = '\0';
	if (local_flag.width)
	{
		if (local_flag.precision)
			local_flag.zero = ' ';
		if ((offset = local_flag.width - (int)ft_strlen(string)) > 0)
		{
			if (local_flag.negative == -1)
			{
				string = ft_strjoin("-", string);
				offset--;
			}
			string = fill_line(string, offset, local_flag);
		}
	}
	return (string);
}

void	draw_integer(struct s_flags *flag, va_list *ap)
{
	int num;
	char *string;

	num = va_arg(*ap, int);
	if (((num < 0) && (flag->zero == '0')) || ((num < 0) && (flag->precision)))
		flag->negative = -1;

	string = ft_itoa(num * flag->negative);
	string = string_builder(string, flag);
	ft_putstr(string);
	free(string);
}
