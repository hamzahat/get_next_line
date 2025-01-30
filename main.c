#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
void f()
{
    system("leaks a.out");
}
// bonus main :

int main (void)
{
    int fd1 = open("file_1.txt",O_RDONLY);
    int fd2 = open("file_2.txt",O_RDONLY);
    int fd3 = open("file_3.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        printf("error opeging files\n");
        return (1);
    }
    char *line1;
    char *line2;
    char *line3;

    while ((line1 = get_next_line(fd1)) || (line2 = get_next_line(fd2)) || (line3 = get_next_line(fd3)))
    {
        if (line1)
        {
            printf("FD1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("FD2: %s", line2);
            free(line2);
        }
        if (line3)
        {
            printf("FD3: %s", line3);
            free(line3);
        }
    }
    // line1 = get_next_line(fd1);
    // printf("FD1: %s", line1); // expected: hello
    // free(line1);
    // line2 = get_next_line(fd2);
    // printf("FD2: %s", line2); // expected: world
    // free(line2);
    // line1 = get_next_line(fd1);
    // printf("FD1: %s", line1); // expected: i'm 0backgrond
    // free(line1);
    // line2 = get_next_line(fd2);
    // printf("FD2: %s", line2); // expected: blackhole
    // free(line2);

    close(fd1);
    close(fd2);
    close(fd3);
    
    return (0);
}
// mandatory main : 
// int main(void)
// {
//    atexit(f);
//     int fd = open("file.txt", O_RDONLY);
//     if (fd == -1)
//         return (1);
//     char *line;
// // call 1
//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);
// // call 2
//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);
// // cll 3
//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);
// // call 4
//     // line = get_next_line(fd);
//     // printf("%s", line);
//     // free(line);
    
//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     fflush(stdout);

//     return (0);
// }