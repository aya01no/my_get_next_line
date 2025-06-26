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
