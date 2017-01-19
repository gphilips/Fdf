#include "libft.h"

char	*ft_strdup_to_c(char *str, char c)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(str);
	dest = ft_strnew(len);
	i = 0;
	while (str[i] != c && i < len)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
