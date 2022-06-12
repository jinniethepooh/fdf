/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:46:19 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/12 20:20:37 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	max_len(float x, float y)
{
	if (fabs(x) > fabs(y))
		return (fabs(x));
	return (fabs(y));
}

void	get_distance(t_dot *dot)
{
	dot->distance = max_len(dot->screen_ex - dot->screen_bx, \
			dot->screen_ey - dot->screen_by);
	dot->step_x = (dot->screen_ex - dot->screen_bx) / dot->distance;
	dot->step_y = (dot->screen_ey - dot->screen_by) / dot->distance;
}

void	apply_angle(t_info *info, t_dot *dot)
{
	dot->screen_bx = info->offset_x + (cos(info->angle_h) * dot->screen_bx);
	dot->screen_by = info->offset_y + (sin(info->angle_v) * dot->screen_by);
	dot->screen_ex = info->offset_x + (cos(info->angle_h) * dot->screen_ex);
	dot->screen_ey = info->offset_y + (sin(info->angle_v) * dot->screen_ey);	
}

// void	get_render_info(t_info *info, t_dot *dot, char axis)
// {
// 	dot->screen_bx = (dot->flag_x - dot->flag_y) * info->tile_size * info->mode;
// 	dot->screen_by = (dot->flag_x + dot->flag_y) * info->tile_size - \
// 			(info->tab[dot->flag_y][dot->flag_x] * info->z_scale);
// 	if (axis == 'H')
// 	{
// 		dot->screen_ex = (dot->flag_x + 1 - dot->flag_y) * \
// 				info->tile_size * info->mode;
// 		dot->screen_ey = (dot->flag_x + 1 + dot->flag_y) * \
// 				info->tile_size - \
// 				(info->tab[dot->flag_y][dot->flag_x + 1] * \
// 				info->z_scale);
// 	}
// 	else if (axis == 'V')
// 	{
// 		dot->screen_ex = (dot->flag_x - dot->flag_y - 1) * \
// 				info->tile_size * info->mode;
// 		dot->screen_ey = (dot->flag_x + dot->flag_y + 1) * \
// 				info->tile_size - \
// 				(info->tab[dot->flag_y + 1][dot->flag_x] * \
// 				info->z_scale);
// 	}
// 	apply_angle(info, dot);
// }

// ----- FOR 2D ----- //
// void	get_render_info(t_info *info, t_dot *dot, char axis)
// {
	// info->tile_size *= 2;
// 	dot->screen_bx = dot->flag_x * info->tile_size;
// 	dot->screen_by = (dot->flag_y * info->tile_size);
// 	if (axis == 'H')
// 	{
// 		dot->screen_ex = (dot->flag_x + 1) * info->tile_size;
// 		dot->screen_ey = (dot->flag_y * info->tile_size);
// 	}
// 	else if (axis == 'V')
// 	{
// 		dot->screen_ex = dot->flag_x * info->tile_size;
// 		dot->screen_ey = (dot->flag_y + 1) * info->tile_size;
// 	}
// 	apply_angle(info, dot);
// }

void	get_render_info(t_info *info, t_dot *dot, char axis)
{
	dot->screen_bx = 	(
							(dot->flag_x * cos(info->angle_h)) - \
							(dot->flag_y * sin(info->angle_h))
						) * info->tile_size * info->mode;
	dot->screen_by = 	(
							(dot->flag_x * sin(info->angle_h)) + \
							(dot->flag_y * cos(info->angle_h)) - \
							info->tab[dot->flag_y][dot->flag_x] * info->z_scale) * \
							info->tile_size;
	if (axis == 'H')
	{
		dot->screen_ex = (((dot->flag_x + 1) * cos(info->angle_h)) - \
							(dot->flag_y * sin(info->angle_h))) \
							* info->tile_size * info->mode;
		dot->screen_ey = (((dot->flag_x + 1) * sin(info->angle_h)) + \
							((dot->flag_y - info->tab[dot->flag_y][dot->flag_x + 1] * info->z_scale) * cos(info->angle_h))) * \
							info->tile_size;
	}
	else if (axis == 'V')
	{
		dot->screen_ex = ((dot->flag_x * cos(info->angle_h)) - \
							((dot->flag_y + 1) * sin(info->angle_h))) \
							* info->tile_size * info->mode;
		dot->screen_ey = ((dot->flag_x * sin(info->angle_h)) + \
							(((dot->flag_y + 1) - \
							info->tab[dot->flag_y + 1][dot->flag_x] * info->z_scale) * cos(info->angle_h))) \
							* info->tile_size;
	}
	dot->screen_bx += info->offset_x;
	dot->screen_by += info->offset_y;
	dot->screen_ex += info->offset_x;
	dot->screen_ey += info->offset_y;	
	// apply_angle(info, dot);
}