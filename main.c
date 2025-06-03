#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*stash_kiridasi(char *stash);

int main(void)
{
	char *stash = "hello\nworld\n";
	char *line;

	line = stash_kiridasi(stash);
	if (line)
		printf("切り出した一行: %s\n", line);
	else
		printf("NULLが返されました\n");
	return(0);
}

size_t	ft_strlen(const char *s)
{
	size_t	s_len;

	s_len = 0;
	while (s[s_len])
		s_len++;
	return (s_len);
}

char	*stash_kiridasi(char *stash)
{
	int		i;
	char	*nmade;

	i = 0;
	nmade = malloc(ft_strlen(stash));
	while (stash[i] != '\n')
	{
		nmade[i] = stash[i];
		i++;
	}
	nmade[i] = '\n';
	return (nmade);
}
