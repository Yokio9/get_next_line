/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:28:43 by dimatayi          #+#    #+#             */
/*   Updated: 2024/11/01 12:22:34 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_me(char *str)
{
	free(str);
	return (NULL);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len1 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	joined = (char *)ft_calloc(len1 + ft_strlen(s2) + 2, sizeof(char));
	if (!joined)
		return (free_me((char *)s1));
	while (s1[j])
		joined[i++] = s1[j++];
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

/* char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	char	*str1;
	char	*str2;
	size_t	len1;
	size_t	len;

	str1 = (char *)s1;
	str2 = (char *)s2;
	len1 = 0;
	if (str1)
		len1 = ft_strlen(str1);
	len = len1 + ft_strlen(str2) + 2;
	joined = (char *)ft_calloc(len, sizeof(char));
	if (!joined)
		return (free_me(str1));
	if (len1)
		ft_strlcat(joined, str1, len);
	ft_strlcat(joined, str2, len);
	free(str1);
	return (joined);
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
} */

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

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
