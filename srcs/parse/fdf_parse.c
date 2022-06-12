/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:52 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/11 23:20:52 by cchetana         ###   ########.fr       */
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

void	matrix_realloc(t_info *info)
{
	int	i;

	info->tab = (int **)malloc(sizeof(int *) * info->row);
	if (!info->tab)
		error_msg_matrix(info, -1);
	i = 0;
	while (i < info->row)
	{
		info->tab[i] = (int *)malloc(sizeof(int) * info->col);
		if (!info->tab[i])
			error_msg_matrix(info, i);
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
	t_counter	tmp;

	tmp.tmp = read_map(info);
	if (!tmp.tmp)
		error_msg_matrix(info, -1);
	tmp.i = 0;
	tmp.y = 0;
	while (tmp.tmp[tmp.i] && tmp.y < info->row)
	{
		tmp.x = 0;
		while (tmp.tmp[tmp.i] && tmp.tmp[tmp.i] != '\n' && tmp.x < info->col)
		{
			if (ft_isspace(tmp.tmp[tmp.i]) || !ft_isvalidchar(tmp.tmp[tmp.i]))
				tmp.i++;
			info->tab[tmp.y][tmp.x] = ft_atoi(&tmp.tmp[tmp.i]);
			tmp.i += loop_matrix(&tmp.tmp[tmp.i]);
			tmp.x++;
		}
		tmp.i++;
		tmp.y++;
	}
	free(tmp.tmp);
}

void	matrix_init(t_info *info)
{
	get_matrix_row_col(info);
	matrix_realloc(info);
	get_matrix_info(info);
	recenter(info);
}
