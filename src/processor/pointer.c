
#include "../include/ft_printf.h"

static void num_to_hex(unsigned long long num)
{
	char *string;
	char *preffix;

	ft_putnbr(num);

	preffix = ft_strdup("0x");
	string = malloc(sizeof(char) * 12);

	char		*ft_hex(char *hex, unsigned long int h, int razr, char reg)
	{
		int		o;

		hex[razr--] = '\0';
		while (razr >= 0)
		{
			o = h % 16;
			if (h > 16 && o > 9)
				hex[razr] = reg + (o - 9);
			else if (h > 16 && o <= 9)
				hex[razr] = o + '0';
			else if (h < 16 && h > 9)
				hex[razr] = reg + (h - 9);
			else if (h <= 9)
				hex[razr] = h + '0';
			else
				hex[razr] = '0';
			razr--;
			h = h / 16;
		}
		return (hex);
	}


}

void	draw_pointer(struct s_flags *flag, va_list *ap)
{
	unsigned long long num;
	print_flags(flag);
	num = va_arg(*ap, unsigned long long);
	num_to_hex(num);
	printf("\nnum: %llu\n", num);

}
