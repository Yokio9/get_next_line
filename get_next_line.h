#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#define MAX_FD 1024

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*first_line(int fd, char *buffer);
char	*next_line(char *buffer);
char	*last_line(char *buffer);
char	*fill_line(char *buffer, int i);
int		ft_find_char(char *s, int c);
void	*ft_calloc(size_t elem, size_t size);
size_t	ft_strlen(const char *s);
char	*gnl_strjoin(const char *s1, const char *s2);
char	*free_me(char *str);

#endif
