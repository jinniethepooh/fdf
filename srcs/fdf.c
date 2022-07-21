/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:20:33 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:20:46 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		error_msg_invalid_input();
	set_info(&info, argv[1]);
	matrix_init(&info);
	map_render(&info);
	mlx_mouse_hook(info.mlx_win, mouse_press, &info);
	mlx_hook(info.mlx_win, EXIT_CLICK, 0, close_window, &info);
	mlx_key_hook(info.mlx_win, key_press, &info);
	mlx_loop(info.mlx);
	close_window(&info);
	return (0);
}
