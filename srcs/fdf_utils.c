/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:25 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/09 02:03:13 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     get_file_len(char *map_name)
{
    int     fd;
    int     len;
    char    tmp;

    fd = open(map_name, O_RDONLY);
    len = 0;
    while (read(fd, &tmp, 1))
        len++;
    close(fd);
    return (len);
}

void recenter(t_info *info)
{
    int   delta_x;
    int   delta_y;

    delta_x = (info->col - info->row) * info->tile_size * 1.5;
    delta_y = (info->col + info->row) * info->tile_size - \
                (info->tab[info->row - 1][info->col - 1] - info->tab[0][0]);
    info->offset_x = info->offset_x - (delta_x / 2);
    info->offset_y = info->offset_y - (delta_y / 2);
}

void    set_default(t_info *info, char *s)
{
    ft_isvalidfd(s);
    info->mlx = mlx_init();
    info->col = 0;
    info->row = 1;
    info->tile_size = 10;
    info->z_scale = 1;
    info->mode = 1.5;
    info->angleH = 90;
    info->angleV = 0;
    info->mlx_win = mlx_new_window(info->mlx, WIDTH_WIN, HEIGHT_WIN, "fdf");
	info->img_ptr = mlx_new_image(info->mlx, WIDTH_WIN, HEIGHT_WIN);
	info->addr = mlx_get_data_addr(info->img_ptr, &info->bpp, &info->line_len, &info->end);
    info->map_name = s;
    info->offset_x = WIDTH_WIN / 2;
    info->offset_y = HEIGHT_WIN / 2;
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

    if (x < 0 || x >= WIDTH_WIN || y < 0 || y >= HEIGHT_WIN)
		return ;
	dst = info->addr + (y * info->line_len + x * (info->bpp / 8));
	*(unsigned int *)dst = color;
}