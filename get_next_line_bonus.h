/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalbano <dalbano@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:56:44 by dalbano           #+#    #+#             */
/*   Updated: 2024/10/23 18:16:39 by dalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

/* ---------- GNL ------------ */
char	*get_next_line(int fd);

/* ---------- UTILS ---------- */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s, size_t n);
int		read_and_store(int fd, char **storage);
char	*extract_line(char **storage);

#endif /* GET_NEXT_LINE_BONUS_H */