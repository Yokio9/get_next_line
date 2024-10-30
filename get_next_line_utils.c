/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:28:43 by dimatayi          #+#    #+#             */
/*   Updated: 2024/10/29 17:29:51 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	len;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	joined = (char *)ft_calloc(len, sizeof(char));
	if (!joined)
		return (NULL);
	ft_strlcat(joined, (char *)s1, len);
	ft_strlcat(joined, (char *)s2, len);
	free_me(s1);
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
		i = n;
		dstlen = ft_strlen(dest);
		while (n--)
			((char *)dest)[n] = ((const char *)src)[n];
		while (dstlen >= i)
			((char *)dest)[dstlen--] = '\0';
		return (dest);
	}
}
