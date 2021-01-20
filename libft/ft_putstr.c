#include "libft.h"

int	ft_putstr(char *s)
{
	ft_putstr_fd(s, 1);

	return (ft_strlen(s));
}
