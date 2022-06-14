/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_valid_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:20:15 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/14 22:28:28 by jinnie           ###   ########.fr       */
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
	return (('0' <= c && c <= '9') || c == '-' || c == '+');
}

void	ft_isvalidfd(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		error_msg_invalid_fd();
	close(fd);
}
