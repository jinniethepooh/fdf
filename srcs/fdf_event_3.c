/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:41:48 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/05 15:32:01 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_press(int keycode, t_info *info)
{
    if (keycode == ESC_KEY)
    {
        mlx_destroy_window(info->mlx, info->mlx_win);
        free(info->tab);
        exit(0);
    }
    if (keycode == LEFT_KEY)
        info->offset_x -= 10;
    if (keycode == RIGHT_KEY)
        info->offset_x += 10;
    if (keycode == DOWN_KEY)
        info->offset_y -= 10;
    if (keycode == UP_KEY)
        info->offset_y += 10;
    return (0);
}