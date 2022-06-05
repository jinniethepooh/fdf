/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:25 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/04 22:11:48 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     ft_isspace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

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

void    set_default(t_info *info, char *s)
{
    info->mlx = mlx_init();
    info->col = 0;
    info->row = 1;
    info->tile_size = 10;
    // info->tile_size = 5;
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


    // int i;

	// i = (y * info->line_len) + (x * (info->bpp / 8));
    // info->addr[i] = color;
    // info->addr[i + 1] = color >> 8;
    // info->addr[i + 2] = color >> 16;
    // info->addr[i + 3] = 0;
    // ((int *)info->addr)[(y * WIDTH_WIN) + x] = color;
}