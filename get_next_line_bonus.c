/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:53:13 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/20 12:19:39 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char **storage)
{
	char	*newline_pos;
	char	*line;
	char	*remaining;

	if (!storage || !*storage)
		return (NULL);
	newline_pos = ft_strchr(*storage, '\n');
	if (newline_pos)
	{
		line = ft_strndup(*storage, newline_pos - *storage + 1);
		if (!line)
			return (NULL);
		remaining = ft_strdup(newline_pos + 1);
		free(*storage);
		*storage = remaining;
	}
	else
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

int	read_and_store(int fd, char **storage)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*temp;

	if (!*storage)
		*storage = ft_strdup("");
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*storage, buffer);
		if (!temp)
			return (-1);
		free(*storage);
		*storage = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == 0 && *storage && **storage)
		return (0);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	result = read_and_store(fd, &storage[fd]);
	if (result < 0 || (result == 0 && !*storage[fd]))
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	return (extract_line(&storage[fd]));
}

// #include <stdio.h>

// int main() {
//     int fd = open("example.txt", O_RDONLY);
//     char *line;

//     while ((line = get_next_line(fd)) != NULL) {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }
