/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:20:15 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 00:36:44 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' \
			|| c == '\r');
}

int	ft_isvalidchar(char c)
{
	return (('0' <= c && c <= '9') || c == '-');
}

void	ft_isvalidfd(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		error_msg_invalid_fd();
	close(fd);
}

int		ft_ishex(char *s)
{
	int		i;

	i = 0;
	if (s[i] && s[i] == '0')
		i++;
	else 
		return (0);
	if (s[i] && ft_tolower(s[i]) == 'x')
		i++;
	else
		return (0);
	while (s[i] && !ft_isspace(s[i]))
	{
		if (get_hex_index(s[i]) == -1)
			return (0);
		++i;
	}
	return (1);
}