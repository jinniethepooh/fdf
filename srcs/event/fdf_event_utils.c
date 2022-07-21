/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:18:35 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:18:44 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_info *info)
{
	ft_bzero(info->img_px_addr, info->bpp / 8 * WIDTH_WIN * HEIGHT_WIN);
}

int	close_window(t_info *info)
{
	free_matrix_color(info, info->row - 1);
	exit(0);
}
