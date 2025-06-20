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
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*strjoin_and_free(char *stash, char *buf);
char	*ft_strchr(char *s, char *c);
char	*stash_kiridasi(char *stash);
#endif
