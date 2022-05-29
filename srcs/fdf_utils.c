#include "fdf.h"

int     ft_isspace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

int     get_file_len(char *fdf_name)
{
    int     fd;
    int     len;
    char    tmp;

    fd = open(fdf_name, O_RDONLY);
    len = 0;
    while (read(fd, &tmp, 1))
        len++;
    close(fd);
    return (len);
}

void    set_default(t_info *info, char *s)
{
    info->mlx = mlx_init();
    info->win_w = 1400;
    info->win_h = 800;
    info->col = 0;
    info->row = 1;
    info->tile_size = 10;
    info->mlx_win = mlx_new_window(info->mlx, info->win_w, info->win_h, "fdf");
	info->img = mlx_new_image(info->mlx, info->win_w, info->win_h);
	info->addr = mlx_get_data_addr(info->img, &info->bits_per_pixel, &info->line_len, &info->endian);
    info->fdf_name = s;
    info->offset_x = info->win_w / 4;
    info->offset_y = info->win_h / 8;
    
}

void	put_desc(t_info *info)
{
	char	*desc;

	desc = "test test";
	mlx_string_put(info->mlx, info->mlx_win, 10, 10, 0xFFFFFFF, desc);
}

void	get_pixel(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->addr + (y * info->line_len + x * (info->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}