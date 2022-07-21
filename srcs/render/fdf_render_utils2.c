/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:14:09 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:16:25 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_distance(t_dot *dot)
{
	dot->distance = max_len(dot->screen_ex - dot->screen_bx, \
			dot->screen_ey - dot->screen_by);
	dot->step_x = (dot->screen_ex - dot->screen_bx) / dot->distance;
	dot->step_y = (dot->screen_ey - dot->screen_by) / dot->distance;
}

void	get_pixel(t_info *info, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH_WIN || y < 0 || y >= HEIGHT_WIN)
		return ;
	dst = info->img_px_addr + (y * info->line_len + x * (info->bpp / 8));
	*(unsigned int *)dst = color;
}

void	recenter(t_info *info)
{
	float	delta_x;
	float	delta_y;

	delta_x = (info->col * cos(info->angle_h) - \
			info->row * sin(info->angle_h)) * \
			info->tile_size * info->mode;
	delta_y = ((info->col * sin(info->angle_h) + \
			info->row * cos(info->angle_h)) * \
			info->tile_size * (cos(info->angle_v) + \
			sin(info->angle_v)) - \
			(info->tab[info->row - 1][info->col - 1] - \
			info->tab[0][0]) * cos(info->angle_v));
	info->offset_x = (WIDTH_WIN - delta_x) / 2;
	info->offset_y = (HEIGHT_WIN - delta_y) / 2;
}
