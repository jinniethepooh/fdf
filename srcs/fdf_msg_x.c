#include "fdf.h"

void    error_msg_input_missing()
{
    ft_putstr_fd("[error] please provide .fdf file [ ./fdf <filename>.fdf ]", 2);
    exit(0);
}

void    error_msg_invalid_fd()
{
    ft_putstr_fd("[error] invalid input file", 2);
    exit(0);
}