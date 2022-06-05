/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:50:58 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/05 15:35:54 by jinnie           ###   ########.fr       */
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
	mlx_key_hook(info.mlx_win, key_press, &info);
	// mlx_loop_hook(info.mlx_win, key_press, &info);
	mlx_loop(info.mlx);
	free(info.tab);
	return (0);
}