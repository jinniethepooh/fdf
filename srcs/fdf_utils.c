/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:21:18 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:21:25 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_instruction(t_info *info)
{
	mlx_string_put(info->mlx, info->mlx_win, 5, 25, 0xFFFFFF, "=== FDF ===");
	mlx_string_put(info->mlx, info->mlx_win, 5, 50, 0xFFFFFF, "MODE:");
	mlx_string_put(info->mlx, info->mlx_win, 10, 70, 0xFFFFFF, \
			"i (iso), p (parallel)");
	mlx_string_put(info->mlx, info->mlx_win, 5, 95, 0xFFFFFF, \
			"MOVE: arrow - up, left, right, down");
	mlx_string_put(info->mlx, info->mlx_win, 5, 120, 0xFFFFFF, \
			"ZOOM: scroll mouse");
	mlx_string_put(info->mlx, info->mlx_win, 5, 145, 0xFFFFFF, "ROTATE:");
	mlx_string_put(info->mlx, info->mlx_win, 10, 165, 0xFFFFFF, \
			"left - a, right - d,");
	mlx_string_put(info->mlx, info->mlx_win, 10, 185, 0xFFFFFF, \
			"up - w, down - s");
	mlx_string_put(info->mlx, info->mlx_win, 5, 210, 0xFFFFFF, "RESET: r");
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
	info->angle_h = M_PI / 3;
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
	info->angle_h = M_PI / 3;
	info->angle_v = 0;
	info->accum_x = 0;
	info->accum_y = 0;
	recenter(info);
}

float	max_len(float x, float y)
{
	if (fabs(x) > fabs(y))
		return (fabs(x));
	return (fabs(y));
}
