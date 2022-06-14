
#include "fdf.h"

void	recenter(t_info *info)
{
	float	delta_x;
	float	delta_y;

	delta_x = (info->col * cos(info->angle) - info->row * sin(info->angle)) * info->tile_size * info->mode;
	delta_y = ((info->col * sin(info->angle) + info->row * cos(info->angle)) * info->tile_size * (cos(info->angle_v) + sin(info->angle_v)) - \
		(info->tab[info->row - 1][info->col - 1] - info->tab[0][0]) * cos(info->angle_v));
	info->offset_x = (WIDTH_WIN - delta_x) / 2;
	info->offset_y = (HEIGHT_WIN - delta_y) / 2;
}

// ----- FOR 2D ----- //
// void	get_render_info_2d(t_info *info, t_dot *dot, char axis)
// {
// 	info->tile_size *= 2;
// 	dot->screen_bx = dot->flag_x * info->tile_size;
// 	dot->screen_by = dot->flag_y * info->tile_size;
// 	if (axis == 'H')
// 	{
// 		dot->screen_ex = (dot->flag_x + 1) * info->tile_size;
// 		dot->screen_ey = dot->flag_y * info->tile_size;
// 	}
// 	else if (axis == 'V')
// 	{
// 		dot->screen_ex = dot->flag_x * info->tile_size;
// 		dot->screen_ey = (dot->flag_y + 1) * info->tile_size;
// 	}
//     apply_offset(info, dot);
// 	// apply_angle(info, dot);
// }
