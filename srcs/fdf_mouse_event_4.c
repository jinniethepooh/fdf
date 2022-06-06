/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_event_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 23:37:28 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/06 08:03:12 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int mousecode, t_info *info)
{
    if (mousecode == 17)
        close_window(info);
    else if (mousecode == LEFT_CLICK)
        info->tile_size += 1;
    // detect zero
    else if (mousecode == RIGHT_CLICK)
        if (info->tile_size > 0)
            info->tile_size -= 1;
    clear_image(info);
    mlx_clear_window(info->mlx, info->mlx_win);
    map_render(info);
    return (0);
}