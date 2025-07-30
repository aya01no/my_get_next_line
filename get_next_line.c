/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayayamad <ayayamad@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-07 04:23:15 by ayayamad          #+#    #+#             */
/*   Updated: 2025-06-07 04:23:15 by ayayamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*strjoin_and_free(char *stash, char *buf)
{
	char	*dst;
	int		stash_len;
	int		buf_len;

	if (!stash)
		stash_len = 0;
	else
		stash_len = ft_strlen(stash);
	buf_len = ft_strlen(buf);
	dst = malloc((stash_len + buf_len + 1) * sizeof(char));
	if (!dst)
	{
		free(stash);
		return (NULL);
	}
	if (stash)
	{
		ft_memcpy(dst, stash, ft_strlen(stash));
		free(stash);
	}
	ft_memcpy(dst + stash_len, buf, buf_len + 1);
	return (dst);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (stash && ft_strchr(stash, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		stash = strjoin_and_free(stash, buf);
		if (!stash)
			break ;
	}
	free(buf);
	return (stash);
}

static char	*extract_stash(char *stash)
{
	char	*line;
	size_t	len;

	if (!stash || !*stash)
		return (NULL);
	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, len);
	line[len] = '\0';
	return (line);
}

static char	*update_stash(char *old_stash)
{
	size_t	i;
	size_t	old_len;
	char	*new_stash;

	if (!old_stash)
		return (NULL);
	i = 0;
	while (old_stash[i] && old_stash[i] != '\n')
		i++;
	if (old_stash[i] == '\0')
	{
		free(old_stash);
		return (NULL);
	}
	i++;
	old_len = ft_strlen(old_stash);
	if (i >= old_len)
	{
		free(old_stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(old_stash) - i));
	free(old_stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_stash(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash);
	return (line);
}
