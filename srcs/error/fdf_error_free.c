/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:36:37 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/11 18:00:17 by cchetana         ###   ########.fr       */
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

void	free_matrix(t_info *info, int index)
{
	int	i;

	mlx_destroy_image(info->mlx, info->img_ptr);
	mlx_destroy_window(info->mlx, info->mlx_win);
	i = index;
	while (i >= 0)
	{
		free(info->tab[i]);
		--i;
	}
	free(info->tab);
}
