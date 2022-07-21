/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:19:06 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:20:20 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int mousecode, int x, int y, t_info *info)
{
	(void)x;
	(void)y;
	if (mousecode == EXIT_CLICK)
		close_window(info);
	if (mousecode == SCROLL_UP)
		info->tile_size += 1;
	if (mousecode == SCROLL_DOWN)
		if (info->tile_size > 3)
			info->tile_size -= 1;
	recenter(info);
	clear_image(info);
	mlx_clear_window(info->mlx, info->mlx_win);
	map_render(info);
	return (0);
}
