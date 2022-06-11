/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:25 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/11 17:50:31 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	recenter(t_info *info)
{
	int	delta_x;
	int	delta_y;

	delta_x = (info->col - info->row) * info->tile_size * 1.5;
	delta_y = (info->col + info->row) * info->tile_size - \
		(info->tab[info->row - 1][info->col - 1] - info->tab[0][0]);
	info->offset_x = info->offset_x - (delta_x / 2);
	info->offset_y = info->offset_y - (delta_y / 2);
}

void	set_img(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		error_msg_mlx();
	info->mlx_win = mlx_new_window(info->mlx, WIDTH_WIN, HEIGHT_WIN, "fdf");
	if (!info->mlx_win)
	{
		free_mlx_win(info);
		error_msg_mlx();
	}
	info->img_ptr = mlx_new_image(info->mlx, WIDTH_WIN, HEIGHT_WIN);
	if (!info->img_ptr)
	{
		free_img(info);
		error_msg_img();
	}
	info->img_px_addr = mlx_get_data_addr(info->img_ptr, &info->bpp, \
			&info->line_len, &info->end);
	if (!info->img_px_addr)
	{
		free_img(info);
		error_msg_img();
	}
}

void	set_info(t_info *info, char *s)
{
	ft_isvalidfd(s);
	info->col = 0;
	info->row = 1;
	info->tile_size = 10;
	info->z_scale = 1;
	info->mode = 1.5;
	info->angle_h = 90;
	info->angle_v = 0;
	info->map_name = s;
	info->offset_x = WIDTH_WIN / 2;
	info->offset_y = HEIGHT_WIN / 2;
	set_img(info);
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
	dst = info->img_px_addr + (y * info->line_len + x * (info->bpp / 8));
	*(unsigned int *)dst = color;
}
