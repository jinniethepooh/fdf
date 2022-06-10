/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_msg_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 22:12:05 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/11 03:27:06 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_msg_input_missing(void)
{
	ft_putstr_fd("[error] input .fdf file [ ./fdf <filename>.fdf ]", 2);
	exit(0);
}

void	error_msg_invalid_fd(void)
{
	ft_putstr_fd("[error] invalid input file", 2);
	exit(0);
}
