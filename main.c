#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
void f()
{
    system("leaks test_gnl");
}

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);

//    atexit(f);
    
    return (0);
}
