/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:47:23 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 01:03:40 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_file_len(char *map_name)
{
	int		fd;
	int		len;
	char	tmp;

	fd = open(map_name, O_RDONLY);
	len = 0;
	while (read(fd, &tmp, 1))
		len++;
	close(fd);
	return (len);
}

int	loop_matrix(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !ft_isspace(s[i]))
		i++;
	while (s[i] && ft_isspace(s[i]) && s[i] != '\n')
		i++;
	return (i);
}

int		get_hex_index(char c)
{
	char	*hex;
	int	i;

	hex = "0123456789abcdef";
	i = 0;
	while (hex[i])
	{
		if (ft_tolower(c) == hex[i])
			return (i);
		++i;
	}
	return (-1);
}

int	get_hex_color(char *s)
{
	int	color;
	int	i;

	color = 0;
	i = 2;
	while (s[i] && !ft_isspace(s[i]))
	{
		color = (color * 16) + get_hex_index(s[i]);
		++i;
	}
	return (color);
}

int	get_matrix_color(t_info *info, t_counter *t, int index)
{
	int	len;

	len = loop_matrix(&t->tmp[index]);
	while (t->tmp[index] && !ft_isspace(t->tmp[index]) && t->tmp[index] != ',')
		index++;
	if (t->tmp[index] == ',' && ft_ishex(&t->tmp[index + 1]))
		info->tabc[t->y][t->x] = get_hex_color(&t->tmp[index + 1]);
	else
		info->tabc[t->y][t->x] = 0xFFFFFF;
	return (len);
}
