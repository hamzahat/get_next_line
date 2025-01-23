/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:33:52 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/01/23 16:58:13 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *final_line(char *line_buffer)
{
	char    *static_buf;
	ssize_t    i;

	i = 0;
	/*
	 * This loop let's us find the end of the line
	 * either when we encounter a \n or a \0
	 */
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	/* here we check if the current or next character is a \0
	 * if this is the case, this means that the line is empty so
	 * we return NULL, this is what the subject asks us, send NULL
	 * if there is no next line
	 */
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	/* here we take a substring from the end of the line to the end
	 * of the whole line_buffer, that's what's left from our line
	 */
	static_buf = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*static_buf == 0)
	{
		free(static_buf);
		static_buf = NULL;
	}
	/* don't forget to set the last character to \0 to NUL-terminate
	 * the line
	 */    
	line_buffer[i + 1] = 0;
	return (static_buf);
}

static char	*catch_the_newline(int fd, char *static_buf, char *buffer)
{
	ssize_t	readen;
	char	*tmp;

	readen = 1;
	while (readen > 0)
	{
		readen = read(fd, buffer, BUFFER_SIZE);
		if (readen == -1)
		{
			free(static_buf);
			return (NULL);
		}
		else if (readen == 0)
			break ;
		buffer[readen] = 0;
		tmp = static_buf;
		static_buf = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (static_buf);
}
//static char    *ft_strchr(char *s, int c);

char    *get_next_line(int fd)
{
	static char *static_buf;
	char        *line;
	char        *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE >= INT_MAX)
	{
		free(static_buf);
		static_buf = NULL;
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
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
