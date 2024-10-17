#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(sizeof(char) * len);
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	ft_strlcat(joined, (char *)s1, len);
	ft_strlcat(joined, (char *)s2, len);
	return (joined);
}

int	*ft_strchr(const char *s, int c)
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
	return (NULL);
}

char *get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;

	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (ft_strchr(str, '\n')) //strrchr retourne l'index apres le \n
		{
			line = ft_strjoin(); //coller de str a str + le resultat de strchr
		}
	}
}

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
			printf("%s", str);
			free(str);
			str = get_next_line(fd);
		}
		fclose(fichier);
	}
	printf("\n\nbuffer size: %d", BUFFER_SIZE);
	return (0);
}
