/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:28:35 by dimatayi          #+#    #+#             */
/*   Updated: 2024/10/19 10:28:35 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((char *)s)[n] = c;
	return (s);
}

char	*lst_chr(char *buffer, char **line, char **str)
{
	if (*buffer)
	{
		*line = ft_strdup(*str);
		if (!(*line))
			return (NULL);
		return (*line);
	}
	else
	{
		if (*str)
		{
			free(*str);
			*str = NULL;
		}
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		return (NULL);
	}
}

char	*management(int index, char **line, char **str, char *buffer)
{
	*line = calloc(index + 1, sizeof(char));
	if (!*line)
		return (NULL);
	ft_strlcpy(*line, *str, index);
	*str = ft_strjoin("", *str + index);
	if (!*str)
		return (NULL);
	ft_memset(buffer, 0, BUFFER_SIZE);
	return (*line);
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
		if (!str)
			return (NULL);
		index = ft_char_found(str, '\n');
		if (index)
		{
			line = management(index, &line, &str, buffer);
			return (line);
		}
	}
	return (lst_chr(buffer, &line, &str));
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
			printf("%s", str);
			free(str);
			str = get_next_line(fd);
		}
		fclose(fichier);
	}
	return (0);
}
