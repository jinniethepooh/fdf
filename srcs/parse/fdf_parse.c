/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <cchetana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:52 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/11 17:56:08 by cchetana         ###   ########.fr       */
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
		error_msg_matrix();
	i = 0;
	while (i < info->row)
	{
		info->tab[i] = (int *)malloc(sizeof(int) * info->col);
		if (!info->tab[i])
		{
			free_matrix(info, i);
			error_msg_matrix();
		}
		i++;
	}
}

void	get_matrix_row_col(t_info *info)
{
	int		i;
	char	*tmp;

	tmp = read_map(info);
	if (!tmp)
		return ;
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
	free(tmp);
}

void	get_matrix_info(t_info *info)
{
	int		x;
	int		y;
	int		i;
	char	*tmp;

	tmp = read_map(info);
	if (!tmp)
		return ;
	i = 0;
	y = 0;
	while (tmp[i] && y < info->row)
	{
		x = 0;
		while (tmp[i] && tmp[i] != '\n' && x < info->col)
		{
			if (ft_isspace(tmp[i]) || !ft_isvalidchar(tmp[i]))
				i++;
			info->tab[y][x] = ft_atoi(&tmp[i]);
			i += loop_matrix(&tmp[i]);
			x++;
		}
		i++;
		y++;
	}
	free(tmp);
}

void	matrix_init(t_info *info)
{
	get_matrix_row_col(info);
	matrix_realloc(info);
	get_matrix_info(info);
	recenter(info);
}
