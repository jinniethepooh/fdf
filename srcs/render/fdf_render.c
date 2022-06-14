/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:59 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/15 01:26:25 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	put_hrender(t_info *info, t_dot *dot)
{
	if (dot->flag_x + 1 < info->col)
	{
		get_render_info(info, dot, 'H');
		get_distance(dot);
		while ((int)(dot->screen_ex - dot->screen_bx) || \
				(int)(dot->screen_ey - dot->screen_by))
		{
			dot->screen_color = set_color(info, dot, dot->flag_x, dot->flag_y);
			get_pixel(info, dot->screen_bx, dot->screen_by, \
					dot->screen_color);
			dot->screen_bx += dot->step_x;
			dot->screen_by += dot->step_y;
		}
		get_pixel(info, dot->screen_bx, dot->screen_by, \
				dot->screen_color);
	}
}

static void	put_vrender(t_info *info, t_dot *dot)
{
	if (dot->flag_y + 1 < info->row)
	{
		get_render_info(info, dot, 'V');
		get_distance(dot);
		while ((int)(dot->screen_ey - dot->screen_by) || \
				(int)(dot->screen_ex - dot->screen_bx))
		{
			dot->screen_color = set_color(info, dot, dot->flag_x, dot->flag_y);
			get_pixel(info, dot->screen_bx, dot->screen_by, \
					dot->screen_color);
			dot->screen_bx += dot->step_x;
			dot->screen_by += dot->step_y;
		}
		get_pixel(info, dot->screen_bx, dot->screen_by, \
				dot->screen_color);
	}
}

void	map_render(t_info *info)
{
	t_dot	dot;

	dot.flag_y = 0;
	while (dot.flag_y < info->row)
	{
		dot.flag_x = 0;
		while (dot.flag_x < info->col)
		{
			put_hrender(info, &dot);
			put_vrender(info, &dot);
			dot.flag_x++;
		}
		dot.flag_y++;
	}
	mlx_put_image_to_window(info->mlx, info->mlx_win, \
			info->img_ptr, 0, 0);
	fdf_instruction(info);
}
