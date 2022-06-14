/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:19:09 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/15 01:26:18 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(t_dot *dot)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

	percentage = fabs((dot->screen_ey - dot->screen_by) / dot->distance);
    red = get_light((0x349598 >> 16) & 0xFF, (0xFF00000 >> 16) & 0xFF, percentage);
    green = get_light((0x349598 >> 8) & 0xFF, (0xFF00000 >> 8) & 0xFF, percentage);
    blue = get_light(0x349598 & 0xFF, 0xFF00000 & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

int	set_color(t_info *info, t_dot *dot, int x, int y)
{
	if (x + 1 < info->col && (info->tab[y][x] || info->tab[y][x + 1]))
		return (get_color(dot));
	else if (y + 1 < info->row && (info->tab[y][x] || info->tab[y + 1][x]))
		return (get_color(dot));
	else
		return (0xFFFFFFF);
}
