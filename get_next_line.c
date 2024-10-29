/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:28:35 by dimatayi          #+#    #+#             */
/*   Updated: 2024/10/29 17:34:41 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t elem, size_t size)
{
	void	*p;

	p = malloc(elem * size);
	if (!p)
		return (NULL);
	while (elem--)
		((char *)p)[elem] = 0;
	return (p);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src && n > 0)
		return (NULL);
	if ((dest < src) && (dest + n > src))
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
		return (dest);
	}
	else
	{
		while (n--)
			((char *)dest)[n] = ((const char *)src)[n];
		return (dest);
	}
}

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

void	*free_me(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}

char *get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	int			index;
	int			chr_read;

	line = NULL;
	str = NULL;
	buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	chr_read = 1;
	while (chr_read > 0 && fd >= 0 && BUFFER_SIZE > 0)
	{
		chr_read = read(fd, buffer, BUFFER_SIZE);
		if (!chr_read)
			break;
/* 		if (chr_read <= 0 && !str)
			free_me(buffer); */
		buffer[chr_read] = '\0';
		str = gnl_strjoin(str, buffer);
		if (!str)
		{
			return (free_me(buffer));
		}
		index = ft_char_found(str, '\n');
		if (index)
		{
			line = ft_calloc(index + 1, sizeof(char));
			if (!line)
			{
				free_me(buffer);
			}
			ft_strlcpy(line, str, index + 1);
			str = ft_memmove(str, str + index, ft_strlen(str - index));
			//line = management(index, &line, &str, &buffer);
			return (line);
		}
	}
	return (str);
	//return (lst_chr(buffer, &line, &str));
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *str;

	fd = open("test.txt", O_RDONLY);
	if (fd)
	{
		str = get_next_line(fd);
		while (str != NULL)
		{
			printf("%s", str);
			free(str);
			str = get_next_line(fd);
		}
		close(fd);
	}
	return 0;
}
