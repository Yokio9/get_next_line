#include "get_next_line.h"

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

int	ft_char_found(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i + 1);
		i++;
	}
	if (s[i] == (char)c)
		return (i + 1);
	return (0);
}

char *get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			index;
	int			chr_read;

	while ((chr_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[chr_read] = '\0';
		str = ft_strjoin(str, buffer);
		index = ft_char_found(str, '\n');
		if (index)
		{
			line = calloc(index + 1, sizeof(char));
			ft_strlcpy(line, str, index);
			str = ft_strjoin("", str + index);
			return (line);
		}
	}
	if (read(fd, buffer, BUFFER_SIZE) == 0)
	{
		line = ft_strdup(str);
		free(str);
		str = NULL;
		return (line);
	}
	return (NULL);
}

#include <stdio.h>
int main()
{
	FILE	*fichier;
	int		fd;
	char	*str;
	fichier = fopen("test.txt", "r");
	if (fichier)
	{
		fd = fileno (fichier);
		str = get_next_line(fd);
		while (str != NULL)
		{
			printf("%s\n", str);
			free(str);
			str = get_next_line(fd);
		}
		fclose(fichier);
	}
	return (0);
}
