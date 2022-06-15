/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:19:09 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 01:07:51 by jinnie           ###   ########.fr       */
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
    red = get_light((0xFFE5CC >> 16) & 0xFF, (0xFF00000 >> 16) & 0xFF, percentage);
    green = get_light((0xFFE5CC >> 8) & 0xFF, (0xFF00000 >> 8) & 0xFF, percentage);
    blue = get_light(0xFFE5CC & 0xFF, 0xFF00000 & 0xFF, percentage);
    return ((red << 16) | (green << 8) | blue);
}

int	set_color(t_info *info, t_dot *dot, int x, int y)
{
	int	color;

	color = info->tabc[y][x];
	if (color != 0xFFFFFF)
		return (color);
	if (x + 1 < info->col && (info->tab[y][x] || info->tab[y][x + 1]))
		return (get_color(dot));
	if (y + 1 < info->row && (info->tab[y][x] || info->tab[y + 1][x]))
		return (get_color(dot));
	return (0xFFFFFF);
}
