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
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*last_line(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i + j])
		j++;
	new_buffer = malloc(sizeof(char) * (j + 1));
	if (!new_buffer)
		return (free(buffer), NULL);
	j = -1;
	while (buffer[i + ++j] != '\0')
		new_buffer[j] = buffer[i + j];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
/* 	char *temp;
	int	index;
	int	i;

	if (!*buffer)
	{
		free(buffer);
		return (NULL);
	}
	index = ft_find_char(buffer, '\n');
	i = index;
	while (buffer[index])
		index++;
	temp = (char *)ft_calloc(index + 1, sizeof(char));
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	ft_strlcat(temp, buffer, index - i + 1);
	free(buffer);
	return (temp); */
}
char	*first_line(char *buffer)
{
//	int		index;
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	i = ft_find_char(buffer, '\n');
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);

/* 	if (!*buffer)
		return (NULL);
	index = ft_find_char(buffer, '\n');
	line = ft_cat(buffer, index);
	if (!line)
		return (NULL);
	return (line); */
}

char	*read_line(int fd, char *buffer)
{
	int		chr_read;
	char	*str;

	str = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	chr_read = 1;
	while (chr_read > 0)
	{
		chr_read = read(fd, str, BUFFER_SIZE);
		if (chr_read < 0)
		{
			free(str);
			return (NULL);
		}
		str[chr_read] = '\0';
		buffer = gnl_strjoin(buffer, str);
		if (!buffer)
		{
			free(str);
			return (NULL);
		}
		if (ft_find_char(str, '\n'))
			break;
	}
	free(str);
	return (buffer);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0 || fd < 0)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = first_line(buffer);
	buffer = last_line(buffer);
/* 	if (!line)
		return (free_me(buffer)); */
	return (line);
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
