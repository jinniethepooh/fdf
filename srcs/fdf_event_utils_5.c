#include "fdf.h"

void    clear_image(t_info *info)
{
    ft_bzero(info->addr, info->bpp / 8 * WIDTH_WIN * HEIGHT_WIN);
}

int close_window(t_info *info)
{
    mlx_destroy_window(info->mlx, info->mlx_win);
    free(info->tab);
    exit(0);
}