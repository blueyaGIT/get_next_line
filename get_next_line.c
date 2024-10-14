/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:53:13 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/14 10:47:26 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char **storage)
{
	char	*newline_pos;
	char	*line;
	char	*remaining;

	newline_pos = ft_strchr(*storage, '\n');
	if (!newline_pos)
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
		return (line);
	}
	line = ft_strndup(*storage, newline_pos - *storage + 1);
	remaining = ft_strdup(newline_pos + 1);
	free(*storage);
	*storage = remaining;
	return (line);
}

static int	read_and_store(int fd, char **storage)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*storage, buffer);
		free(*storage);
		*storage = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	int			result;

	storage = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = read_and_store(fd, &storage);
	if (result < 0 || (result == 0 && !storage))
		return (NULL);
	return (extract_line(&storage));
}

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
