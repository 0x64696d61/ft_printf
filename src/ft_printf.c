#include "../include/ft_printf.h"
#include "../libft/libft.h"

int parse_line(char *str, va_list *ap)
{
	int counter, byte, width, offset;
	unsigned int uint;
	char *string;

	counter = 0;
	while(*str)
	{
		if (*str == '%')
		{
				counter++;
				str++;
				if (ft_isdigit(*str))
				{
					printf("width option ....\n");
					width = ft_atoi(str);
					while(ft_isdigit(*str))
						str++;
				}
				if (*str == 's')
				{
					string = va_arg(*ap, char*);
					if (((int)ft_strlen(string)) < width)
						offset = width - ft_strlen(string);
						while(offset--)
							printf(" ");
					printf("%s", string);
				}
				else if (*str == 'c')
				{
					byte = va_arg(*ap, int);
					printf("%c", byte);
				}
				else if (*str == 'u')
				{
					uint = va_arg(*ap, int);
					printf("%d", uint);
				}
				else if (*str == '%')
				{
					printf("%c", '%');
				}
				else
					printf("code requared");

		}
		else
			printf("%c", *str);
		str++;
	}
	return (counter);
}

int ft_printf(char *line, ...)
{
	char **str = &line;
	struct s_flags *flag;
	va_list ap;
	va_start(ap, line);


	while(**str != '\0')
	{
		flag = init_flags();
		flag = line_parser(str, flag);

		if (check_flags(flag) == 1)
		{
			run_processor(flag, &ap);
		}
		if (**str != '\0')
			(*str)++;
	}

	va_end(ap);
	return 0;
}
