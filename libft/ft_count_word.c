#include "libft.h"

int		ft_count_word(const char *s, char c)
{
	int	i;
	int	count;
	int is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (s[i++])
	{
		if (is_word == 1 && s[i] == c)
			is_word = 0;
		if (is_word == 1 && s[i] != c)
		{
			is_word = 1;
			count++;
		}
	}
	return (count);
}
