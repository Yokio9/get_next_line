/* void	*ft_calloc(size_t elem, size_t size)
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

char	*lst_chr(char *buffer, char **line, char **str)
{
	if (*buffer)
	{
		free(buffer);
		buffer = NULL;
		*line = ft_strdup(*str);
		if (!(*line))
			return (NULL);
		return (*line);
	}
	else
	{
		if (*str)
		{
			*line = ft_strdup(*str);
			free(*str);
			*str = NULL;
			return (*line);
		}
		else if (*line)
		{
			free(*line);
			*line = NULL;
		}
		return (NULL);
	}
}

char	*management(int index, char **line, char **str, char **buffer)
{
	char *temp;
	*line = calloc(index + 1, sizeof(char));
	if (!*line)
		return (NULL);
	ft_strlcpy(*line, *str, index + 1);
	temp = ft_strdup(*str);
	free(*str);
	*str = ft_strdup(temp + index);
	if (!*str)
		return (NULL);
	free(temp);
	free(*buffer);
	return (*line);
}

void	*free_me(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
} */