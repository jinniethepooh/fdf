/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:43:46 by cchetana          #+#    #+#             */
/*   Updated: 2022/05/29 23:13:57 by jinnie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

typedef struct s_info
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*fdf_name;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;

	int		win_h;
	int		win_w;

	int		tile_size;

	int		col;
	int		row;
	int		offset_x;
	int		offset_y;
	int		**tab;

	// /*	COORDINATE */
	// float		x;
	// float		y;
	// float		z;
	
	// double		angle;
	
}		t_info;

typedef	struct s_dot
{
	float   screen_bx;
    float   screen_by;
    float   screen_ex;
    float   screen_ey;
    float   distance;
    float   step_x;
    float   step_y;
    int     screen_color;
	char	dir;
}		t_dot;


void    set_default(t_info *info, char *s);
void    matrix_init(t_info *info);
void	get_pixel(t_info *info, int x, int y, int color);
void    map_render(t_info *info);
void	put_desc(t_info *info);

int     ft_isspace(char c);
int     get_file_len(char *fdf_name);

#endif