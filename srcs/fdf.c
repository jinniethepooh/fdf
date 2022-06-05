/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:50:58 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/05 13:15:43 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_info	info;
	// t_var	event;

	set_default(&info, argv[1]);
	matrix_init(&info);

	// int	x, y;

	// y = 0;
	// printf("\n-----\n");
	// while (y < info.row)
	// {
	// 	x = 0;
	// 	while (x < info.col)
	// 	{
	// 		printf("%d, ", info.tab[y][x]);
	// 		++x;
	// 	}
	// 	printf("\n");
	// 	++y;
	// }

	// recenter(&info);
	// map_render(&info);
	// mlx_key_hook(info.mlx_win, key_press, &info);
	// mlx_loop(info.mlx);
	free(info.tab);
	return (0);
}