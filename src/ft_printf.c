#include "../include/ft_printf.h"
#include "../libft/libft.h"

int ft_printf(char *line, ...)
{
	struct s_flags *flag;
	char **str;
	int counter;
	va_list ap;

	str = &line;
	counter = 0;
	va_start(ap, line);
	while(**str != '\0')
	{
		flag = init_flags();
		flag = line_parser(str, flag, &counter);
	//	printf("%d\n", counter);
		if (check_flags(flag) == 1)
		{
			counter += run_processor(flag, &ap);
		}
		if (**str != '\0')
			(*str)++;
	}

	va_end(ap);
	//printf("%d\n", counter);
	//counter = 100;
	return (counter);
}
