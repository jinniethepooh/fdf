/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:17:42 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:17:51 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_mlx_win(t_info *info)
{
	mlx_destroy_window(info->mlx, info->mlx_win);
}

void	free_img(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img_ptr);
	mlx_destroy_window(info->mlx, info->mlx_win);
}

void	free_matrix_info(t_info *info, int index)
{
	int	i;

	free_img(info);
	i = index;
	while (i >= 0)
	{
		free(info->tab[i]);
		--i;
	}
	free(info->tab);
}

void	free_matrix_color(t_info *info, int index)
{
	int	i;

	free_matrix_info(info, info->row - 1);
	i = index;
	while (i >= 0)
	{
		free(info->tabc[i]);
		--i;
	}
	free(info->tabc);
}
