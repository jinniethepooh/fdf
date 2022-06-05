/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:19:09 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/05 23:35:40 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     set_color(t_info *info, int x, int y)
{
    if (x + 1 < info->col && (info->tab[y][x] || info->tab[y][x + 1]))
        return (0xFF00000);
    else if (y + 1 < info->row && (info->tab[y][x] || info->tab[y + 1][x]))
        return (0xFF00000);
    else
        return (0xFFFFFFF); 
}