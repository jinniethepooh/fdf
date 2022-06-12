/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:50:58 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/12 04:06:20 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_menu_selector(t_info *info)
{
	mlx_string_put(info->mlx, info->mlx_win, 15, 30, 0xFFFFFF, "FDF");
	mlx_string_put(info->mlx, info->mlx_win, 15, 55, 0xFFFFFF, "==>");
	mlx_string_put(info->mlx, info->mlx_win, 15, 75, 0xFFFFFF, "ISO: I Key");
	mlx_string_put(info->mlx, info->mlx_win, 15, 100, 0xFFFFFF, "PAR: P Key");
	// mlx_string_put(info->mlx, info->mlx_win, 57, y += 30, 0xFFFFFF, "Parallel - Multi view");
	// mlx_string_put(info->mlx, info->mlx_win, 30, y + 25, 0xFFFFFF, "==>");
	// mlx_string_put(info->mlx, info->mlx_win, 57, y += 25, 0xFFFFFF, "Top Vue: T");
	// mlx_string_put(info->mlx, info->mlx_win, 30, y + 25, 0xFFFFFF, "==>");
	// mlx_string_put(info->mlx, info->mlx_win, 57, y += 25, 0xFFFFFF, "Right Vue: R");
	// mlx_string_put(info->mlx, info->mlx_win, 30, y + 25, 0xFFFFFF, "==>");
	// mlx_string_put(info->mlx, info->mlx_win, 57, y += 25, 0xFFFFFF, "Front Vue: F");
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		error_msg_input_missing();
	set_info(&info, argv[1]);
	matrix_init(&info);
	map_render(&info);
	projection_menu_selector(&info);
	mlx_mouse_hook(info.mlx_win, mouse_press, &info);
	mlx_hook(info.mlx_win, EXIT_CLICK, 0, close_window, &info);
	mlx_key_hook(info.mlx_win, key_press, &info);
	mlx_loop(info.mlx);
	close_window(&info);
	return (0);
}
