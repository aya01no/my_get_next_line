/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayayamad <ayayamad@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-07 05:32:39 by ayayamad          #+#    #+#             */
/*   Updated: 2025-06-07 05:32:39 by ayayamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	// "1char.txt"という名前で、中身が"0"だけのファイルを作成
	fd = open("1char.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(fd, "0", 1);
	close(fd);
	// 作成したファイルを開いてテスト
	fd = open("1char.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: open failed\n");
		return (1);
	}
	// 1回目の呼び出し
	printf("Calling gnl 1st time...\n");
	line = get_next_line(fd);
	printf("-> Received line: [%s]\n", line);
	free(line);
	// 2回目の呼び出し
	printf("\nCalling gnl 2nd time...\n");
	line = get_next_line(fd);
	printf("-> Received line: [%s]\n", line);
	free(line); // lineがNULLでもfree(NULL)は安全
	printf("\nTest finished.\n");
	close(fd);
	return (0);
}
