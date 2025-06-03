/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayayamad <ayayamad@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-29 08:19:23 by ayayamad          #+#    #+#             */
/*   Updated: 2025-05-29 08:19:23 by ayayamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	return (s_len);
}

char	*strjoin_and_free(char *stash, char *buf)
{
	char		*dst;
	size_t		i;
	size_t		j;

	dst = malloc((ft_strlen(stash) + ft_strlen(buf) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (i < ft_strlen(stash))
	{
		dst[i] = stash[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(buf))
	{
		dst[i + j] = buf[j];
		j++;
	}
	dst[i + j] = '\0';
	free(stash);
	return (dst);
}

char	*strnchr(char *s, char *c)
{
	while (*s && *s != c)
		s++;
	if (*s != c)
		return (NULL);
	else
		return ((char *)s);
}

char	*stash_kiridasi(char *stash)
{
	char	*nmade;
	size_t	i;

	nmade = malloc(ft_strlen(stash) + 1);
	while (stash[i] != '\n')
	{
		nmade[i] = stash[i];
		i++;
	}
	nmade[i] = '\n';
	return (nmade);
}

char	*get_next_line(int fd)
{
	char			*buf;
	static char		*stash;
	char			*tmp;
	ssize_t			bytes_read;

	stash = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	i = 0;
	while (strnchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		tmp = strjoin_and_free(stash, buf);
	}
	stash = tmp;
	return (stash_kiridasi(stash));
}
