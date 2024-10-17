#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	if (!ft_strlen(src))
		ft_strlcpy(dst, src, 1);
	else
		ft_strlcpy(dst, src, ft_strlen(src) + 1);
	return (dst);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	joined = (char *)malloc(sizeof(char) * len);
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	ft_strlcat(joined, (char *)s1, len);
	ft_strlcat(joined, (char *)s2, len);
	return (joined);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (dst_size > 0)
	{
		while (src[i] && i < dst_size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	dst_len = i;
	src_len = ft_strlen(src);
	if (dstsize <= dst_len || dstsize == 0)
		return (src_len + dstsize);
	while (src[j] != '\0' && j < dstsize - dst_len - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
