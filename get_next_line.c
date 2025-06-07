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

// fdを受け取って、そこから一行ずつ読んで、改行したらそこまで
// 文字を返す。もしくはnull
// 改行文字が来るまでbuffer_size分readして、bufにいれておく
// buffer_size終わっても改行来なかったら、再度readを実行
// 改行がくるまでそれを繰り返し、なおかつ一回目以降はbufに
// 入っている文字に今読み込んだ文字を追加したものをstashにいれる
// 改行文字が来た、もしくはbyte_readゼロ(=ファイルの残り0)
// のとき、stashから改行文字になるまで(bufから追加済)出力する（一文字ずつ？）
// 出力が終わったら（returnする前？後？）stashの改行文字までをfreeする
char	*get_next_line(int fd)
{

	char			*buf;
	static char		*stash;
	char			*tmp;
	ssize_t			bytes_read;

	stash = NULL;
	if (BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (ft_strchr(stash, "\n") && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		tmp = strjoin_and_free(stash, buf);
	}
	stash = tmp;
	return (stash_kiridasi(stash));
}
