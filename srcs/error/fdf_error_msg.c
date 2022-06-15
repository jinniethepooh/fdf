/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:12:05 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/15 12:18:45 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_msg_input_missing(void)
{
	ft_putstr_fd("[ERROR] input .fdf file [ ./fdf <filename>.fdf ]", 2);
	exit(0);
}

void	error_msg_invalid_fd(void)
{
	ft_putstr_fd("[ERROR] invalid input file", 2);
	exit(0);
}

void	error_msg_mlx(t_info *info)
{
	if (!info->mlx_win)
		free_mlx_win(info);
	ft_putstr_fd("[ERROR] could not initilize mlx window", 2);
	exit(0);
}

void	error_msg_img(t_info *info)
{
	free_img(info);
	ft_putstr_fd("[ERROR] could not initilize image", 2);
	exit(0);
}

void	error_msg_matrix_info(t_info *info, int index)
{
	free_matrix_info(info, index);
	ft_putstr_fd("[ERROR] could not malloc map", 2);
	exit(0);
}

void	error_msg_matrix_color(t_info *info, int index)
{
	free_matrix_color(info, index);
	ft_putstr_fd("[ERROR] could not malloc map color", 2);
	exit(0);
}
