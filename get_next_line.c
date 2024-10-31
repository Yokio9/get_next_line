/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:28:35 by dimatayi          #+#    #+#             */
/*   Updated: 2024/10/30 17:38:12 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_char(const char *s, int c)
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
	int	i;

	if (str)
	{
		i = ft_strlen(str);
		while (i--)
			(str)[i] = 0;
	}
	free(str);
	str = NULL;
	return (NULL);
}

char	*last_line(char *str, char *buffer)
{
	char *temp;
	int	strlen;
	int	index;
	int	size;

	if (buffer)
		free_me(buffer);
	if (str)
	{
		strlen = ft_strlen(str);
		if (!strlen)
			return (NULL);
		index = ft_find_char(str, '\n');
		if (index)
			size = index;
		else
			size = strlen;
		temp = (char *)ft_calloc(size + 1, sizeof(char));
		if (!temp)
			return (NULL);
		ft_strlcat(temp, str, size + 1);
		free_me(str);
		return (temp);
	}
	return (NULL);
}
char	*get_current_line(char **buffer)
{
	int		index;
	char	*line;

	index = ft_find_char(*buffer, '\n');
	line = gnl_strjoin(*buffer, index + 1);
	if (!line)
		return (NULL);
	*buffer = ft_memmove(*buffer, *buffer + index, ft_strlen(line) - index);
	return (line);
}

char	read_line(int fd, char *buffer)
{
	int		chr_read;
	char	*str;

	str = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!str)
		return (NULL);
	chr_read = 1;
	while (chr_read > 0)
	{
		chr_read = read(fd, str, BUFFER_SIZE);
		if (chr_read < 0)
			return (free_me(str));
		if (chr_read == 0)
			break;
		str[chr_read] = '\0';
		buffer = gnl_strjoin(buffer, str);
		if (!buffer)
			return (free_me(str));
		if (ft_find_char(str, '\n'))
			break;
	}
	free_me(str);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0 || fd < 0)
		return (free_me(buffer));
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_current_line(&buffer);
	if (!line)
		return (free_me(buffer));
/* 	chr_read = 1;
	while (chr_read > 0 && fd >= 0 && !index)
	{
		chr_read = read(fd, buffer, BUFFER_SIZE);
		if (chr_read < 0)
		{
			return (free_me(buffer));
		}
		if (chr_read == 0)
			break;
		buffer[chr_read] = '\0';
		str = gnl_strjoin(str, buffer);
		if (!str)
		{
			return (free_me(buffer));
		}
		index = ft_char_found(str, '\n');
	}
	if (str)
		index = ft_char_found(str, '\n');
	if (index)
	{
		line = ft_calloc(index + 1, sizeof(char));
		if (!line)
		{
			return (free_me(buffer));
		}
		ft_strlcat(line, str, index + 1);
		str = ft_memmove(str, str + index, ft_strlen(str) - index);
		free_me(buffer);
		return (line);
	}
	line = last_line(str, buffer);
	str = NULL;
	return (line); */
}

/* #include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *str;

	fd = open("42_with_nl", O_RDONLY);
	if (fd)
	{
		str = get_next_line(fd);
		while (str != NULL)
		{
			printf("%s", str);
			free(str);
			str = get_next_line(fd);
		}
		if (str == NULL)
			printf("\nstr = NULL");
		else
			printf("\nstr != NULL");
		close(fd);
	}
	return 0;
} */
