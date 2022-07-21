/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:13:49 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:13:56 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	apply_offset(t_info *info, t_dot *dot)
{
	dot->screen_bx += (info->offset_x + info->accum_x);
	dot->screen_by += (info->offset_y + info->accum_y);
	dot->screen_ex += (info->offset_x + info->accum_x);
	dot->screen_ey += (info->offset_y + info->accum_y);
}

static float	get_adj_coord(int flag_x, int flag_y, t_info *info, char coord)
{
	float	x;
	float	y;

	x = flag_x * info->tile_size;
	y = flag_y * info->tile_size;
	if (coord == 'x')
	{
		x *= info->mode;
		y *= info->mode;
		return (x * cos(info->angle_h) - y * sin(info->angle_h));
	}
	else if (coord == 'y')
		return (((x * sin(info->angle_h) + y * cos(info->angle_h)) * \
					(cos(info->angle_v) + sin(info->angle_v))) - \
					(info->tab[flag_y][flag_x] * info->z_scale) * \
					cos(info->angle_v));
	return (0);
}

void	get_render_info(t_info *info, t_dot *dot, char axis)
{
	dot->screen_bx = get_adj_coord(dot->flag_x, dot->flag_y, info, 'x');
	dot->screen_by = get_adj_coord(dot->flag_x, dot->flag_y, info, 'y');
	if (axis == 'H')
	{
		dot->screen_ex = get_adj_coord(dot->flag_x + 1, dot->flag_y, info, 'x');
		dot->screen_ey = get_adj_coord(dot->flag_x + 1, dot->flag_y, info, 'y');
	}
	else if (axis == 'V')
	{
		dot->screen_ex = get_adj_coord(dot->flag_x, dot->flag_y + 1, info, 'x');
		dot->screen_ey = get_adj_coord(dot->flag_x, dot->flag_y + 1, info, 'y');
	}
	apply_offset(info, dot);
}
