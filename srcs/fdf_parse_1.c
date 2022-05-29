#include "fdf.h"

int     loop_matrix(char *s)
{
    int     i;

    i = 0;
    while (s[i] && !ft_isspace(s[i]) && s[i] != '\n')
        i++;
    while (s[i] && ft_isspace(s[i]) && s[i] != '\n')
        i++;
    return (i);
}

char    *read_map(t_info *info)
{
    int         fd;
    int         i;
    char        *tmp;

    i = 0;
    tmp = (char *)malloc(sizeof(char) * get_file_len(info->fdf_name) + 1);
    if (!tmp)
        return (NULL);
    fd = open(info->fdf_name, O_RDONLY);
    while (read(fd, &tmp[i], 1))
        i++;
    close(fd);
    return (tmp);
}

void    matrix_realloc(t_info *info)
{
    int i;

    info->tab = (int **)malloc(sizeof(int *) * info->row);
    if (!info->tab)
        return ;
    i = 0;
    while (i < info->row)
    {
        info->tab[i] = (int *)malloc(sizeof(int) * info->col);
        i++;
    }
}

void    get_matrix_row_col(t_info *info)
{
    int         i;
    char        *tmp;

    tmp = read_map(info);
    if (!tmp)
        return ;
    i = 0;
    while (tmp[i] && tmp[i] != '\n')
    {
        if (!ft_isspace(tmp[i]))
            info->col++;
        i += loop_matrix(&tmp[i]);
    }
    while (tmp[i++])
        if (tmp[i] == '\n')
            info->row++;
    free(tmp);
}

void    get_matrix_info(t_info *info)
{
    int         x;
    int         y;
    int         i;
    char    *tmp;

    tmp = read_map(info);
    if (!tmp)
        return ;
    i = 0;
    y = 0;
    while (tmp[i] && y < info->row)
    {
        x = 0;
        while (tmp[i] && tmp[i] != '\n' && x < info->col)
        {
            info->tab[y][x] = ft_atoi(&tmp[i]);
            i += loop_matrix(&tmp[i]);
            x++;
        }
        i++;
        y++;
    }
    free(tmp);
}

void    matrix_init(t_info *info)
{   
    get_matrix_row_col(info);
    matrix_realloc(info);
    get_matrix_info(info);
}