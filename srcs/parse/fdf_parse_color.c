/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:09:52 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:10:23 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_hex_index(char c)
{
	char	*hex;
	int		i;

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
