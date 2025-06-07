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


char	*get_next_line(int fd)
{
	static char		*stash;
	char			*tmp;
	ssize_t			bytes_read;

	stash = NULL;
	if (BUFFER_SIZE < 0)
		return (NULL);
	stash = malloc(BUFFER_SIZE + 1);
	if (!stash)
		return (NULL);
	bytes_read = read(fd, stash, BUFFER_SIZE);
	while (ft_strchr(stash, "\n") && bytes_read > 0)
	{
		bytes_read = read(fd, stash, BUFFER_SIZE);
		stash[bytes_read] = '\0';
		tmp = strjoin_and_free(stash, buf);
	}
	stash = tmp;
	return (stash_kiridasi(stash));
}
