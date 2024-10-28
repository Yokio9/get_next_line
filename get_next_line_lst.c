#include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

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

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_elem;

	if (!new || !lst)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		last_elem = ft_lstlast(*lst);
		last_elem->next = new;
	}
}

static void	free_elem(t_list *elem, t_list *first_elem, void (*del)(void *))
{
	while (first_elem)
	{
		elem = first_elem;
		first_elem = (first_elem)->next;
		del(elem);
		free(elem);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem;
	t_list	*first_elem;
	void	*new_content;

	if (!lst)
		return (NULL);
	first_elem = ft_lstnew(f(lst->content));
	if (!first_elem)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_content = f(lst->content);
		elem = ft_lstnew(new_content);
		if (!elem)
		{
			del(new_content);
			free_elem(first_elem, elem, del);
			return (NULL);
		}
		ft_lstadd_back(&first_elem, elem);
		lst = lst->next;
	}
	return (first_elem);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

void	*ft_memset(void *s, int c, size_t n)
{
	while (n--)
		((char *)s)[n] = c;
	return (s);
}

void	*ft_calloc(size_t elem, size_t size)
{
	void	*p;

	p = malloc(elem * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, elem * size);
	return (p);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if ((!s))
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (const char *)s + start, len + 1);
	return (sub);
}

char	*cat_lst(int index, t_list *stock)
{
	char	*str;
	int		len;
	char	*temp;

	while (stock)
	{
		len += ft_strlen(stock->content);
		stock = stock->next;
	}
	str = (char *)ft_calloc(len + 1, sizeof(char));
	while (stock != ft_lstlast(stock))
	{
		ft_strlcat(str, stock->content, len + 1);
		stock = stock->next;
	}
	ft_substr(str, 0, index);
	//i want to put everything after the \n into temp
	//clear the begining of the list
	//and trin the string of the last elem in the list
	temp = ft_strdup(ft_substr());
	ft_substr()
	return (str);
}

char *get_next_line(int fd)
{
	static t_list	*stock;
	static int		chr_read;
	char			*buffer;
	int				index;
	char			*line;

	//check if file is valid
	chr_read = 1;
	//stock = ft_lstnew(0);
	buffer = (char *)ft_calloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (chr_read > 0)
	{
		chr_read = read(fd, buffer, BUFFER_SIZE);
		if (chr_read)
		{
			ft_lstadd_back(&stock, ft_lstnew(buffer));
			index = ft_char_found(ft_lstlast(stock->content), '\n');
			if (index)
			{
				line = cat_lst(++index, )
			}
		}
	}
}


char *get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	int			index;
	int			chr_read;


	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || BUFFER_SIZE <= 0)
		return (NULL);
	chr_read = 1;
	memset(buffer, 0, BUFFER_SIZE + 1);
	line = NULL;
	while (chr_read > 0 && fd >= 0 && BUFFER_SIZE > 0)
	{
		chr_read = read(fd, buffer, BUFFER_SIZE);
		if (chr_read <= 0 && !str)
		{
			free(buffer); // write line 92 and 03 in a function for here and for 99 and 100
			return (NULL);
		}
		buffer[chr_read] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
		index = ft_char_found(str, '\n');
		if (index)
		{
			line = management(index, &line, &str, &buffer);
			return (line);
		}
	}
	return (lst_chr(buffer, &line, &str));
}
