
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif /*BUFFER_SIZE*/
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int get_next_line(int const fd, char **line);

#endif /* GET_NEXT_LINE_H */ 