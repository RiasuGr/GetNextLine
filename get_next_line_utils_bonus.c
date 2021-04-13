#include "get_next_line_bonus.h"

unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size)/*done*/
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		dst[i] = '\0';
		i++;
	}
	return (i);
}

int	ft_strchr(const char *str, int *c)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	*c = i;
	if (((c == 0 && str[0] != '\n' ) || (*c == BUFFER_SIZE && str[BUFFER_SIZE] != '\n') 
			|| (!str[*c])))
		return (-1);
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str)
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *dst, char *src, int n)
{
	char	*str;
	int		a;
	int		b;

	a = -1;
	b = -1;
	str = malloc(sizeof(*dst) * (ft_strlen(dst) + n + 1));
	if (!str)
		return (0);
	if(dst)
	{
		while(dst[++a])
			str[a] = dst[a];
	}
	else 
		a = 0;
	while (++b < n)
		str[a + b] = src[b];
	str[a + b] = 0;
	free(dst);
	return (str);
}
