/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:50:58 by cchetana          #+#    #+#             */
/*   Updated: 2022/05/29 21:36:22 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_info	info;

	set_default(&info, argv[1]);
	matrix_init(&info);
	put_desc(&info);
	map_render(&info);
	mlx_loop(info.mlx);
	free(info.tab);
	return (0);
}