#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif /*BUFFER_SIZE*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int get_next_line(int const fd, char **line);
unsigned int	ft_strlcpy(char *dst, char *src, unsigned int size);
int	ft_strchr(const char *str, int *c);
int	ft_strlen(const char *str);
char	*ft_strnjoin(char *dst, char *src, int n);

#endif /* GET_NEXT_LINE_H */ 