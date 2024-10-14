#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
char	*error(FILE *txt)
{
	fclose(txt);
	txt = NULL;
	return (NULL);
}

char *get_next_line(int fd)
{
	static FILE	*txt;
	static int	line_read;
	int			i;
	char		str[BUFFER_SIZE];
	char		*output;

	memset(str, 0, BUFFER_SIZE);
	if (txt == NULL)
	{
		txt = fdopen(fd, "r");
		if (txt == NULL)
			return (NULL);
	}
	i = line_read;
	if (i > 0)
	{
		output = fgets(str, BUFFER_SIZE, txt);
		if(!output)
			return (error(txt));
	}
	line_read++;
	if(!output)
		return (error(txt));
	return (strdup(str));
}

// Almost works perfectly
// Only need to make this work and we're all good
// Votre fonction marche-t-elle encore si la valeur de BUFFER_SIZE
// est de 9999? Ou de 1 ? Ou encore de 10 000 000 ? Savez-vous pourquoi ?

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