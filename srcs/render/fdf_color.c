/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:10:46 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:12:49 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_light(int start, int end, double ratio)
{
	return ((int)((1 - ratio) * start + ratio * end));
}

static int	get_color(t_dot *dot)
{
	int		red;
	int		green;
	int		blue;
	double	ratio;

	ratio = fabs((dot->screen_ey - dot->screen_by) / dot->distance);
	red = get_light((0xFFE5CC >> 16) & 0xFF, (0xFF00000 >> 16) & 0xFF, ratio);
	green = get_light((0xFFE5CC >> 8) & 0xFF, (0xFF00000 >> 8) & 0xFF, ratio);
	blue = get_light(0xFFE5CC & 0xFF, 0xFF00000 & 0xFF, ratio);
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
