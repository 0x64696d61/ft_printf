
#include "../include/ft_printf.h"

char *ft_strtoupper(char *string)
{
	char *p_string;

	p_string = string;
	while(*p_string)
	{
		*p_string = ft_toupper(*p_string);
		p_string++;
	}
	return (string);
}

char  *base_converter(unsigned long long num, int notation)
{
    const char base[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'a','b','c','d','e','f' };
    int mas[64];
    int i = 0;
	char *string;
	char *p_sring;

    while (num != 0)
    {
        mas[i] = num % notation;
        num = num / notation;
		i++;
    }
	string = malloc(sizeof(char) * i + 1);
	string[i] = '\0';
	p_sring = string;
    while(i-- > 0)
		*p_sring++ = base[mas[i]];
	p_sring = string;
	string = ft_strjoin("0x", string);
	free(p_sring);
    return (string);
}


void	draw_pointer(struct s_flags *flag, va_list *ap)
{
	unsigned long long num;
	char *string;
	print_flags(flag);
	num = va_arg(*ap, unsigned long long);
	string = base_converter(num, 16);
	ft_putstr(ft_strtoupper(string));
}
