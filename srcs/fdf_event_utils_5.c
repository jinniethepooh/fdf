/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_utils_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:05:43 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/10 22:06:21 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_info *info)
{
	ft_bzero(info->addr, info->bpp / 8 * WIDTH_WIN * HEIGHT_WIN);
}

int	close_window(t_info *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
	free(info->tab);
	exit(0);
}
