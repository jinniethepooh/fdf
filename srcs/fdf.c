/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:50:58 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/06 13:17:15 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_info	info;

	set_default(&info, argv[1]);
	matrix_init(&info);
	recenter(&info);
	map_render(&info);
	mlx_mouse_hook(info.mlx_win, mouse_press, &info);
	mlx_hook(info.mlx_win, 17, 0, close_window, &info);
	mlx_key_hook(info.mlx_win, key_press, &info);
	// mlx_hook(info.mlx_win, 17, 0, close_window, &info);
	mlx_loop(info.mlx);
	free(info.tab);
	return (0);
}