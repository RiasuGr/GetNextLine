#include "get_next_line.h"

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
int get_next_line(int fd, char **line)
{
	static char buffer[10240][BUFFER_SIZE + 1];
	int		c;
	int 	s;

	*line = 0;
	while(1)
	{
		/*(((c == 0 && str[0] != '\n' ) || (c == BUFFER_SIZE && str[BUFFER_SIZE] != '\n') || (!str[*c]))) */
		if (ft_strchr(buffer[fd], &c) == -1)
		{
			*line = ft_strnjoin(*line, buffer[fd], c);
			ft_strlcpy(buffer[fd], buffer[fd] + c + 1, BUFFER_SIZE - c);
			s = read(fd, buffer[fd], BUFFER_SIZE);
			if (s < 1)
				return (s);
		}
		else
		{
			*line = ft_strnjoin(*line, buffer[fd], c);
			ft_strlcpy(buffer[fd], buffer[fd] + c + 1, BUFFER_SIZE - c);
			return (1);
		}
	}
}