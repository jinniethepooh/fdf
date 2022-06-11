/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_msg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:12:05 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/11 17:55:37 by cchetana         ###   ########.fr       */
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

void	error_msg_mlx(void)
{
	ft_putstr_fd("[ERROR] could not initilize mlx window", 2);
	exit(0);
}

void	error_msg_img(void)
{
	ft_putstr_fd("[ERROR] could not initilize image", 2);
	exit(0);
}

void	error_msg_matrix(void)
{
	ft_putstr_fd("[ERROR] could not malloc map", 2);
	exit(0);
}
