/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:59 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/06 07:53:50 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float     max_len(float x, float y)
{
    if (fabs(x) > fabs(y))
        return (fabs(x));
    return (fabs(y));
}

void    put_Hrender(t_info *info, t_dot *dot, int x, int y)
{
    if (x + 1 < info->col)
    {
        dot->screen_bx = info->offset_x + (x - y) * info->tile_size * 1.5;
        dot->screen_by = info->offset_y + (x + y) * info->tile_size - (info->tab[y][x] * info->z_scale);
        dot->screen_ex = info->offset_x + (x + 1 - y) * info->tile_size * 1.5;
        dot->screen_ey = info->offset_y + (x + 1 + y) * info->tile_size - (info->tab[y][x + 1] * info->z_scale);
        dot->distance = max_len(dot->screen_ex - dot->screen_bx, dot->screen_ey - dot->screen_by);
        dot->step_x = (dot->screen_ex - dot->screen_bx) / dot->distance;
        dot->step_y = (dot->screen_ey - dot->screen_by) / dot->distance;
        dot->screen_color = set_color(info, x, y);
        while ((int)(dot->screen_ex - dot->screen_bx) || (int)(dot->screen_ex - dot->screen_bx))
        {
            get_pixel(info, dot->screen_bx, dot->screen_by, dot->screen_color);
            dot->screen_bx += dot->step_x;
            dot->screen_by += dot->step_y;
        }
        get_pixel(info, dot->screen_bx, dot->screen_by, dot->screen_color);
    }
}

void    put_Vrender(t_info *info, t_dot *dot, int x, int y)
{
    if (y + 1 < info->row)
    {
        dot->screen_bx = info->offset_x + (x - y) * info->tile_size * 1.5;
        dot->screen_by = info->offset_y + (x + y) * info->tile_size - (info->tab[y][x] * info->z_scale);
        dot->screen_ex = info->offset_x + (x - y - 1) * info->tile_size * 1.5;
        dot->screen_ey = info->offset_y + (x + y + 1) * info->tile_size - (info->tab[y + 1][x] * info->z_scale);
        dot->distance = max_len(dot->screen_ex - dot->screen_bx, dot->screen_ey - dot->screen_by);
        dot->step_x = (dot->screen_ex - dot->screen_bx) / dot->distance;
        dot->step_y = (dot->screen_ey - dot->screen_by) / dot->distance;
        dot->screen_color = set_color(info, x, y);
        while ((int)(dot->screen_ey - dot->screen_by) || (int)(dot->screen_ex - dot->screen_bx))
        {
            get_pixel(info, dot->screen_bx, dot->screen_by, dot->screen_color);
            dot->screen_bx += dot->step_x;
            dot->screen_by += dot->step_y;
        }
        get_pixel(info, dot->screen_bx, dot->screen_by, dot->screen_color);
    }
}

void    map_render(t_info *info)
{
    int flag_x;
    int flag_y;
    t_dot   dot;

    flag_y = 0;
    while (flag_y < info->row)
    {
        flag_x = 0;
        while (flag_x < info->col)
        {
            put_Hrender(info, &dot, flag_x, flag_y);
            put_Vrender(info, &dot, flag_x, flag_y);
            flag_x++;
        }
        flag_y++;
    }
    mlx_put_image_to_window(info->mlx, info->mlx_win, info->img_ptr, 0, 0);
}

// void    img_render()