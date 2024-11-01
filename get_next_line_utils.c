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
	free((char *)s1);
	return (joined);
}

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