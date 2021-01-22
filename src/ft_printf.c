#include "../include/ft_printf.h"
#include "../libft/libft.h"

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
	return (3);
}
