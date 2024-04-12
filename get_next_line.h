
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# ifndef DESCRIPTOR_COUNT
#  define DESCRIPTOR_COUNT 4096
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*new_line_reminder(char *line_reminder);
char	*get_line(char *line_reminder);
char	*read_to_line_reminder(int fd, char*line_reminder);

#endif