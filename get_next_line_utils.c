/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:28:43 by dimatayi          #+#    #+#             */
/*   Updated: 2024/10/30 16:56:49 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(const char *s1, const char *s2)
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
	free_me(str1);
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
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
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

void	*ft_memmove(void *dest, const void *src, int n)
{
	int	i;
	int	dstlen;

	if (!dest && !src && n > 0)
		return (NULL);
	dstlen = ft_strlen(dest);
	if ((dest < src) && (dest + n > src))
	{
		i = -1;
		while (++i < n)
			((char *)dest)[i] = ((const char *)src)[i];
		while (i < dstlen)
			((char *)dest)[i++] = '\0';
		return (dest);
	}
	else
	{
		i = n;
		while (n--)
			((char *)dest)[n] = ((const char *)src)[n];
		while (dstlen >= i)
			((char *)dest)[dstlen--] = '\0';
		return (dest);
	}
}
