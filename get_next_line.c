/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:53:13 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/20 10:41:04 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(const char *str)
{

}

char	*ft_switch_line(char **temp, char **storage)
{
	char	*curr_line;

	*temp = ft_strdup(*storage);
	ft_free_content(storage, 0, 0);
	*storage = ft_next_line(*temp);
	curr_line = ft_old_line(*temp);
	ft_free_content(temp, 0, 0);
	return (curr_line);
}

void	ft_read_curr_line(int fd, char **storage, char **temp)
{
	char	*buffer;
	int		i_temp;

	buffer = malloc(sizeof(buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ;
	i_temp = 0;
	while (++i_temp > 0)
	{
		i_temp = read(fd, buffer, BUFFER_SIZE);
		if (i_temp < 0)
		{
			ft_free_content(storage, buffer, i_temp);
			return ;
		}
		buffer[i_temp] = '\0';
		*temp = ft_strdup(*storage);
		ft_free_content(storage, 0, 0);
		*storage = ft_strjoin(*storage, buffer);
		ft_free_content(temp, 0, 0);
		if (ft_is_newline(*storage))
			break ;
	}
	ft_free_content(&buffer, 0, 0);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*curr_line;
	char		*temp;

	storage = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_curr_line(fd, &storage, &temp);
	if (storage != '\0' && storage != NULL)
		curr_line = ft_switch_line(&temp, &storage);
	if (curr_line == NULL || *curr_line == '\0')
	{
		ft_free_content(*temp, &curr_line, &storage);
	}
	return (curr_line);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}