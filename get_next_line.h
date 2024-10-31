#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *src);
char	*gnl_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*get_next_line(int fd);
int		ft_find_char(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *s, int c, size_t n);
char	*lst_chr(char *buffer, char **line, char **str);
char	*management(int index, char **line, char **str, char **buffer);
void	*ft_memmove(void *dest, const void *src, int n);
void	*ft_calloc(size_t elem, size_t size);
char	*last_line(char *str, char *buffer);
void	*free_me(char *str);

#endif
