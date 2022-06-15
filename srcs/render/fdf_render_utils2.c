
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