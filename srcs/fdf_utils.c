/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:25 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/12 19:43:07 by cchetana         ###   ########.fr       */
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
	info->offset_x = (WIDTH_WIN - delta_x) / 2;
	info->offset_y = (HEIGHT_WIN - delta_y) / 2;
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
	info->angle_h = -M_PI / 3;
	info->angle_v = -M_PI / 3;
	info->map_name = s;
	set_img(info);
}

void	get_pixel(t_info *info, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH_WIN || y < 0 || y >= HEIGHT_WIN)
		return ;
	dst = info->img_px_addr + (y * info->line_len + x * (info->bpp / 8));
	*(unsigned int *)dst = color;
}
