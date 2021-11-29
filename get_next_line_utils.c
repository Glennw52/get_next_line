#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

void	*ft_calloc(unsigned int count, size_t size)
{
	char			*ret_ptr;
	unsigned int	i;

	ret_ptr = (void *)malloc(count * size);
	if (ret_ptr == 0)
		return ((void *)ret_ptr);
	i = 0;
	while (i < count * size)
	{
		ret_ptr[i] = 0;
		i++;
	}
	return ((void *)ret_ptr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = (char *)ft_calloc(1, 1);
	ret_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret_str == 0)
		return (ret_str);
	while (s1[i])
	{
		ret_str[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j])
	{
		ret_str[i + j] = s2[j];
		j++;
	}
	ret_str[i + j] = 0;
	return (ret_str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (!(str[i]) && (char)c == 0)
		return ((char *)&str[i]);
	return (0);
}
