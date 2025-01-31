#include "get_next_line.h"
#include <libc.h>

int main (void)
{
    int fd = open("file_1.txt", O_RDONLY);
    char *line = NULL;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
        line = NULL;
    }
    close(fd);
}
