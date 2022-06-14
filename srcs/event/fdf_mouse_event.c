/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:37:28 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/14 22:47:08 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int mousecode, int x, int y, t_info *info)
{
	int	tmp;

	tmp = x;
	tmp = y;
	(void)tmp;
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
