/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:28:35 by dimatayi          #+#    #+#             */
/*   Updated: 2024/11/01 12:28:03 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_char(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (0);
}

char	*fill_line(char *buffer, int i)
{
	int		j;
	char	*output;

	j = 0;
	while (buffer[i + j])
		j++;
	output = malloc(sizeof(char) * (j + 1));
	if (!output)
		return (free_me(buffer));
	j = 0;
	while (buffer[i + j] != '\0')
	{
		output[j] = buffer[i + j];
		j++;
	}
	output[j] = '\0';
	free(buffer);
	return (output);
}

char	*last_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free_me(buffer));
	i++;
	str = fill_line(buffer, i);
	if (!str)
		return (free_me(buffer));
	return (str);
}

char	*first_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
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
			return (free_me(str));
		str[chr_read] = '\0';
		buffer = gnl_strjoin(buffer, str);
		if (!buffer)
			return (free_me(str));
		if (ft_find_char(str, '\n'))
			break ;
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
	return (line);
}
