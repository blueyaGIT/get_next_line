/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:56:44 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/20 10:42:21 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFFER
# endif

/* ---------- GNL ------------ */
char	*get_next_line(int fd);
char	*ft_switch_line(char **temp, char **storage);
void	ft_read_curr_line(int fd, char **storage, char **temp);
char	*ft_old_line(const char *str);
char	*ft_new_line(const char *str);

/* ---------- UTILS ---------- */
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, const char *s2);
int		ft_is_newline(const char *str);
void	ft_free_content(char **ptr, char **ptr1, char **ptr2);

#endif /* GET_NEXT_LINE_H */
