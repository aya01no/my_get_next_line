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

void	read_line(int fd, char *buf, char *stash)
{
	ssize_t	bytes_read;

	while (!(ft_strchr(buf, "\n")) && bytes_read != 0)
	{
		bytes_read = read(fd, buf, (ssize_t)BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			printf("%s", "read error");
		}
		buf[bytes_read] = '\0';
		strjoin_and_free(stash, buf);
	}
	stash_kiridasi(stash);
}

char	*strjoin_and_free(char *stash, char *buf)
{
	char	*dst;
	int		stash_len;
	int		buf_len;

	stash_len = 0;
	if (stash)
		stash_len = ft_strlen(stash);
	buf_len = ft_strlen(buf);
	dst = malloc((stash_len + buf_len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	if (stash)
	{
		ft_memcpy(dst, stash, ft_strlen(stash));
		free(stash);
	}
	ft_memcpy(dst + stash_len, buf, buf_len + 1);
	free(buf);
	stash = dst;
	return (stash);
}

char	*stash_kiridasi(char *stash)
{
	char	*nmade;
	size_t	i;

	nmade = malloc(ft_strlen(stash) + 1);
	if (!nmade)
		return (NULL);
	i = 0;
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
	char		*buf;
	static char	*stash;

	if (BUFFER_SIZE < 0 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_line(fd, buf, stash);
	return (stash_kiridasi(stash));
}
