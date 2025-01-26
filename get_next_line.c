/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:33:52 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/01/26 16:57:05 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *final_line(char *line_buffer)
{
	char    *static_buf;
	ssize_t    i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	static_buf = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (static_buf && !*static_buf)
	{
		free(static_buf);
		static_buf = NULL;
	}

	line_buffer[i + 1] = 0;
	return (static_buf);
}

static char	*catch_the_newline(int fd, char *static_buf, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(static_buf);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		static_buf = ft_strjoin(static_buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (static_buf);
}

char    *get_next_line(int fd)
{
	static char *static_buf;
	char        *line;
	char        *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE > INT_MAX)
	{
		free(static_buf);
		static_buf = NULL;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = catch_the_newline(fd, static_buf, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	static_buf = final_line(line);
	return (line);
}
