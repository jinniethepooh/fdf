/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:09:26 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:09:31 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	matrix_realloc_info(t_info *info)
{
	int	i;

	info->tab = (int **)malloc(sizeof(int *) * info->row);
	if (!info->tab)
		error_msg_matrix_info(info, -1);
	i = 0;
	while (i < info->row)
	{
		info->tab[i] = (int *)malloc(sizeof(int) * info->col);
		if (!info->tab[i])
			error_msg_matrix_info(info, i);
		i++;
	}
}

void	matrix_realloc_color(t_info *info)
{
	int	i;

	info->tabc = (int **)malloc(sizeof(int *) * info->row);
	if (!info->tabc)
		error_msg_matrix_color(info, -1);
	i = 0;
	while (i < info->row)
	{
		info->tabc[i] = (int *)malloc(sizeof(int) * info->col);
		if (!info->tabc[i])
			error_msg_matrix_color(info, i);
		i++;
	}
}
