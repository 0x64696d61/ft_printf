#include "../include/ft_printf.h"

static char	*string_builder(char *string, struct s_flags *flag)
{
	int		offset;
	char	*str;
	char	*str1;

	if (flag->precision)
		if (((int)ft_strlen(string) > flag->precision))
			string[flag->precision] = '\0';
			
		// if ((flag->dot) && (!flag->precision))
		// 	string[0] = '\0';
	if (flag->width)
		if ((offset = flag->width - (int)ft_strlen(string)) > 0)
		{
			str = malloc(sizeof(char*) * offset + 1);
			if (str == NULL)
				printf("error");
			str[offset] = '\0';
			ft_memset(str, flag->zero, offset);
			if (flag->minus)
				str1 = ft_strjoin(string, str);
			else
				str1 = ft_strjoin(str, string);
			free(str);
			free(string);
			return (str1);
		}
	return (string);
}

void draw_u_integer(struct s_flags *flag, va_list *ap)
{
	unsigned int num;
	char *string;

	num = va_arg(*ap, unsigned int);
	string = ft_u_itoa(num);
	string = string_builder(string, flag);
	ft_putstr(string);


}
