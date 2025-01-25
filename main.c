#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
void f()
{
    system("leaks a.out");
}

int main(void)
{
   atexit(f);
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    char *line;
    line = get_next_line(0);
    printf("%s", line);
    free(line);
    line = get_next_line(0);
    printf("%s", line);
    free(line);
    // while ((line = get_next_line(fd)))
    // {
    //     printf("%s", line);
    //     free(line);
    // }
    close(fd);
    fflush(stdout);
    
    return (0);
}
