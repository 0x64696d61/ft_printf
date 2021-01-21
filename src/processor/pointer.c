
#include "../include/ft_printf.h"

int base_converter(unsigned long long num, int notation)
{
    const char base[] = {
        '0','1','2','3','4','5','6','7','8','9',
        'A','B','C','D','E','F' };
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
	ft_putstr(string);

    return 0;
}


void	draw_pointer(struct s_flags *flag, va_list *ap)
{
	unsigned long long num;
	print_flags(flag);
	num = va_arg(*ap, unsigned long long);
	base_converter(num, 16);
//	printf("\nnum: %llu\n", num);

}
