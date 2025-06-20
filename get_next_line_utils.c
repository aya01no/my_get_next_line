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
	if (!s)
		return (NULL);
	while (s[s_len])
		s_len++;
	return (s_len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}

char	*strjoin_and_free(char *stash, char *buf)
{
	char		*dst;
	size_t		stash_len;
	size_t		buf_len;

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

char	*ft_strchr(char *stash, int c)
{
	char	*uc;

	uc = (char *)c;
	while (*stash && *stash != *uc)
		stash++;
	if (*stash != *uc)
		return (NULL);
	else
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
