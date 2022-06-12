/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_event.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:41:48 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/12 02:57:13 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_move_event(int keycode, t_info *info)
{	
	if (keycode == LEFT_KEY)
		info->offset_x -= 10;
	if (keycode == RIGHT_KEY)
		info->offset_x += 10;
	if (keycode == UP_KEY)
		info->offset_y -= 10;
	if (keycode == DOWN_KEY)
		info->offset_y += 10;
}

void	key_steep_event(int keycode, t_info *info)
{
	if (keycode == PLUS_KEY)
		info->z_scale -= 0.25;
	if (keycode == MINUS_KEY)
		info->z_scale += 0.25;
}

void	key_rotate_event(int keycode, t_info *info)
{
	if (keycode == ROTHP_KEY)
		info->angle_h += (5 * M_PI / 180);
	if (keycode == ROTHM_KEY)
		info->angle_h -= (5 * M_PI / 180);
	if (keycode == ROTVP_KEY)
		info->angle_v += (5 * M_PI / 180);
	if (keycode == ROTVM_KEY)
		info->angle_v -= (5 * M_PI / 180);
}

void	key_mode_event(int keycode, t_info *info)
{
	if (keycode == ISO_KEY)
		info->mode = 1.5;
	if (keycode == PAR_KEY)
		info->mode = 1;
}

int	key_press(int keycode, t_info *info)
{
	if (keycode == ESC_KEY)
		close_window(info);
	if (keycode == LEFT_KEY || keycode == RIGHT_KEY || \
			keycode == UP_KEY || keycode == DOWN_KEY)
		key_move_event(keycode, info);
	if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		key_steep_event(keycode, info);
	if (keycode == ROTHP_KEY || keycode == ROTHM_KEY || \
			keycode == ROTVP_KEY || keycode == ROTVM_KEY)
		key_rotate_event(keycode, info);
	if (keycode == ISO_KEY || keycode == PAR_KEY)
		key_mode_event(keycode, info);
	clear_image(info);
	mlx_clear_window(info->mlx, info->mlx_win);
	map_render(info);
	projection_menu_selector(info);
	return (0);
}
