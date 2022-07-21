/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:09:11 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:09:19 by cchetana         ###   ########.fr       */
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
