/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:25 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/14 23:33:49 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_instruction(t_info *info)
{
	mlx_string_put(info->mlx, info->mlx_win, 5, 25, 0xFFFFFF, "=== FDF ===");
	mlx_string_put(info->mlx, info->mlx_win, 5, 50, 0xFFFFFF, "MODE:");
	mlx_string_put(info->mlx, info->mlx_win, 5, 75, 0xFFFFFF, "i (iso), p (parallel)");
	mlx_string_put(info->mlx, info->mlx_win, 5, 100, 0xFFFFFF, "MOVE: arrow - up, left, right, down");
	mlx_string_put(info->mlx, info->mlx_win, 5, 125, 0xFFFFFF, "ZOOM: scroll mouse");
	mlx_string_put(info->mlx, info->mlx_win, 5, 150, 0xFFFFFF, "ROTATE:");
	mlx_string_put(info->mlx, info->mlx_win, 5, 175, 0xFFFFFF, "left - a, right - d,");
	mlx_string_put(info->mlx, info->mlx_win, 5, 200, 0xFFFFFF, "up - w, down - s");
	mlx_string_put(info->mlx, info->mlx_win, 5, 220, 0xFFFFFF, "RESET: r");
}


void	set_img(t_info *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		error_msg_mlx(info);
	info->mlx_win = mlx_new_window(info->mlx, WIDTH_WIN, HEIGHT_WIN, "fdf");
	if (!info->mlx_win)
		error_msg_mlx(info);
	info->img_ptr = mlx_new_image(info->mlx, WIDTH_WIN, HEIGHT_WIN);
	if (!info->img_ptr)
		error_msg_img(info);
	info->img_px_addr = mlx_get_data_addr(info->img_ptr, &info->bpp, \
			&info->line_len, &info->end);
	if (!info->img_px_addr)
		error_msg_img(info);
}

void	set_info(t_info *info, char *s)
{
	ft_isvalidfd(s);
	info->col = 0;
	info->row = 1;
	info->tile_size = 10;
	info->z_scale = 1;
	info->mode = 1.5;
	info->angle = M_PI / 3;
	info->angle_v = 0;
	info->map_name = s;
	info->accum_x = 0;
	info->accum_y = 0;
	set_img(info);
}

void	reset_info(t_info *info)
{
	info->tile_size = 10;
	info->z_scale = 1;
	info->mode = 1.5;
	info->angle = M_PI / 3;
	info->angle_v = 0;
	info->accum_x = 0;
	info->accum_y = 0;
	recenter(info);
}

void	get_pixel(t_info *info, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH_WIN || y < 0 || y >= HEIGHT_WIN)
		return ;
	dst = info->img_px_addr + (y * info->line_len + x * (info->bpp / 8));
	*(unsigned int *)dst = color;
}
