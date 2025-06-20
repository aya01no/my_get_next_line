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

	// readする都度入る　二回目以降はstashにうつす
	char			*buf;
	// bufに入ってるものを保存しておく。\nが来て出力したらそれまでのを削除する
	static char		*stash;
	// これいらなくね？読んだ感じstashの一時保存だけどなくて良さそう この周辺が怪しい
	char			*tmp;
	// readするときのファイルの残り文字　負の数(-1)ならエラーハンドリング　終端は０
	ssize_t			bytes_read;

	//stashの初期化。
	stash = NULL;
	if (BUFFER_SIZE < 0 || BUFFER_SIZE > SSIZE_MAX)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read == -1)
	while (ft_strchr(buf, "\n") && bytes_read > 0)
	{
		
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		tmp = strjoin_and_free(stash, buf);
	}
	stash = tmp;
	return (stash_kiridasi(stash));
}
