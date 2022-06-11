/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:05:43 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/11 17:51:19 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_info *info)
{
	ft_bzero(info->img_px_addr, info->bpp / 8 * WIDTH_WIN * HEIGHT_WIN);
}

int	close_window(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img_ptr);
	mlx_destroy_window(info->mlx, info->mlx_win);
	free_matrix(info, info->row - 1);
	exit(0);
}
