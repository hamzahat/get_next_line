#include "get_next_line_bonus.h"
#include <libc.h>

int main (void)
{
    int fd_1 = open("file_1.txt", O_RDONLY);
    int fd_2 = open("file_2.txt", O_RDONLY);
    int fd_3 = open("file_3.txt", O_RDONLY);

    char *line_1 = NULL;
    char *line_2 = NULL;
    char *line_3 = NULL;

    while (1)
    {
        line_1 = get_next_line(fd_1);
        line_2 = get_next_line(fd_2);
        line_3 = get_next_line(fd_3);

        if (!line_1 && !line_2 && !line_3)
            break;

        if (line_1)
        {
            printf ("%s",line_1);
            free(line_1);
        }
        if (line_2)
        {
            printf ("%s", line_2);
            free(line_2);
        }
        if (line_3)
        {
            printf("%s", line_3);
            free(line_3);
        }
        printf ("\n");
    }
    close(fd_1);
    close(fd_2);
    close(fd_3);
    return (0);
}