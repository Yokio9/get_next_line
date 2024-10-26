#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 999
#endif

#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*get_next_line(int fd);
int		ft_char_found(const char *s, int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *s, int c, size_t n);
char	*lst_chr(char *buffer, char **line, char **str);
char	*management(int index, char **line, char **str, char **buffer);

#endif
