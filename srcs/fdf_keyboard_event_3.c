/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyboard_event_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:41:48 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/06 13:11:44 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    clear_image(t_info *info)
{
    ft_bzero(info->addr, info->bpp / 8 * WIDTH_WIN * HEIGHT_WIN);
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
    if (keycode == PLUS_KEY)
        info->z_scale -= 0.25;
    if (keycode == MINUS_KEY)
        info->z_scale += 0.25;
    // if (keycode == SCROLL_UP)
    //     info->tile_size += 1;
    // // detect zero
    // if (keycode == SCROLL_DOWN)
    //     if (info->tile_size > 0)
    //         info->tile_size -= 1;
    clear_image(info);
    mlx_clear_window(info->mlx, info->mlx_win);
    map_render(info);
    return (0);
}