/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:52 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/15 22:53:06 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*read_map(t_info *info)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * get_file_len(info->map_name) + 1);
	if (!tmp)
		return (NULL);
	fd = open(info->map_name, O_RDONLY);
	while (read(fd, &tmp[i], 1))
		i++;
	close(fd);
	return (tmp);
}

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

char	*get_matrix_row_col(t_info *info)
{
	int		i;
	char	*tmp;

	tmp = read_map(info);
	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		if (!ft_isspace(tmp[i]))
			info->col++;
		i += loop_matrix(&tmp[i]);
	}
	while (tmp[i++])
		if (tmp[i] == '\n')
			info->row++;
	return (tmp);
}

void	get_matrix_info(t_info *info)
{
	t_counter	t;

	t.tmp = read_map(info);
	if (!t.tmp)
		error_msg_matrix_info(info, -1);
	t.i = 0;
	t.y = 0;
	while (t.tmp[t.i] && t.y < info->row)
	{
		t.x = 0;
		while (t.tmp[t.i] && t.tmp[t.i] != '\n' && t.x < info->col)
		{
			if (ft_isspace(t.tmp[t.i]) || !ft_isvalidchar(t.tmp[t.i]))
				t.i++;
			info->tab[t.y][t.x] = ft_atoi(&t.tmp[t.i]);
			// t.i += loop_matrix(&t.tmp[t.i]);
			t.i += get_matrix_color(info, &t, t.i);
			t.x++;
		}
		t.i++;
		t.y++;
	}
	free(t.tmp);
}

void	matrix_init(t_info *info)
{
	get_matrix_row_col(info);
	matrix_realloc_info(info);
	matrix_realloc_color(info);
	get_matrix_info(info);
	recenter(info);
}
