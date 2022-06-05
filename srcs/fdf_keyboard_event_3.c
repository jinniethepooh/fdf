/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_event_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:41:48 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/05 23:54:13 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <strings.h>

void    clear_image(t_info *info)
{
    bzero(info->addr, info->bpp / 8 * WIDTH_WIN * HEIGHT_WIN);
}

int close_window(t_info *info)
{
    mlx_destroy_window(info->mlx, info->mlx_win);
    free(info);
    exit(0);
}

int key_press(int keycode, t_info *info)
{
    if (keycode == ESC_KEY)
        close_window(info);
    if (keycode == LEFT_KEY)
        info->offset_x -= 10;
    if (keycode == RIGHT_KEY)
        info->offset_x += 10;
    if (keycode == UP_KEY)
        info->offset_y -= 10;
    if (keycode == DOWN_KEY)
        info->offset_y += 10;
    clear_image(info);
    mlx_clear_window(info->mlx, info->mlx_win);
    map_render(info);
    return (0);
}