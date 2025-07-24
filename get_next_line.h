/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayayamad <ayayamad@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-02 03:45:38 by ayayamad          #+#    #+#             */
/*   Updated: 2025-06-02 03:45:38 by ayayamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define _POSIX_C_SOURCE 200809L
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*strjoin_and_free(char *stash, char *buf);
int		*ft_strchr(char *stash, int c);
char	*stash_kiridasi(char *stash);
void	*ft_memcpy(void *dst, const void *src, size_t n);
#endif
