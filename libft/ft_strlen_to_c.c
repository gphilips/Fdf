#include "libft.h"

size_t	ft_strlen_to_c(char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i] != c)
		i++;
	return (i);
}

