#include "libft.h"

int		ft_count_word(const char *s, char c)
{
		int	i;
		int	count;

		i = 0;
		count = 0;
		if (s[0] != '\0')
				count++;
		while (s[i])
		{
				if (s[i] == c && s[i + 1] != c)
						count++;
				i++;
		}
		return (count);
}
