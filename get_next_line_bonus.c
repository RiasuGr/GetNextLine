#include "get_next_line_bonus.h"

int get_next_line(int fd, char **line)
{
	static char buffer[128][BUFFER_SIZE + 1];
	int		c;
	int 	s;

	*line = 0;
	if (fd < 0 || fd >= 128  || read(fd, buffer[fd], 0))
		return -1;
	while(1)
	{
		if (ft_strchr(buffer[fd], &c) == -1)
		{
			*line = ft_strnjoin(*line, buffer[fd], c);
			if (!line)
				return (-1);
			ft_strlcpy(buffer[fd], buffer[fd] + c + 1, BUFFER_SIZE - c);
			s = read(fd, buffer[fd], BUFFER_SIZE);
			if (s < 1)
				return (s);
		}
		else
		{
			*line = ft_strnjoin(*line, buffer[fd], c);
			if (!line)
				return (-1);
			ft_strlcpy(buffer[fd], buffer[fd] + c + 1, BUFFER_SIZE - c);
			return (1);
		}
	}
}
