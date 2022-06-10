#include "fdf.h"

int     ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int     ft_isvalidchar(char c)
{
    return (('0' <= c && c <= '9') || c == '-' || c == '+');
}

void     ft_isvalidfd(char *s)
{
    int fd;

    fd = open(s, O_RDONLY);
    if (fd < 0)
        error_msg_invalid_fd();
    close(fd);
}