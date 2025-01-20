/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:33:52 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/01/19 21:01:19 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
// check if fd is valid:
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
// variables:
	static char *static_buff = NULL;
	char temp_buff[BUFFER_SIZE + 1];
	int	bytes_read;

// read from the fd to the buffer:
	bytes_read = read(fd, temp_buff, BUFFER_SIZE);
// check if read fail:
	if (bytes_read <= 0)
		return (NULL);
// terminate the buffer by '\0':
	temp_buff[bytes_read] = 0;
	static_buff = ft_strjoin(static_buff, temp_buff);
	char *new
}











#include <fcntl.h>
int main (void)
{
	int fd = open ("file.txt", O_RDWR);
	if (fd = -1)
		return (-1);
	printf ("%s\n", get_next_line(fd));
}