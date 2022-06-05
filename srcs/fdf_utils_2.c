/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:21:28 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/04 22:35:30 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void recenter(t_info *info)
{
    int   delta_x;
    int   delta_y;

    delta_x = (info->col - info->row) * info->tile_size * 1.5;
    delta_y = (info->col + info->row) * info->tile_size - \
                (info->tab[info->row - 1][info->col - 1] - info->tab[0][0]);
    info->offset_x = info->offset_x - (delta_x / 2);
    info->offset_y = info->offset_y - (delta_y / 2);
}