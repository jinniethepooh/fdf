/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinnie <jinnie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:43:46 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/11 03:31:41 by cchetana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"

# define WIDTH_WIN 1400
# define HEIGHT_WIN 800

//	----- FOR KEYBOARD EVENT ----- //
# define ESC_KEY 53
# define PLUS_KEY 27
# define MINUS_KEY 24
# define ISO_KEY 34
# define PAR_KEY 35
# define ROTHP_KEY 0
# define ROTHM_KEY 2
# define ROTVP_KEY 13
# define ROTVM_KEY 1
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define UP_KEY 126
# define DOWN_KEY 125

//	----- FOR MOUSE EVENT ----- //
# define LEFT_CLICK 1
# define RIGHT_CLICK 2
# define MIDDLE_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define EXIT_CLICK 17

typedef struct s_info
{
	void	*mlx;
	void	*mlx_win;
	void	*img_ptr;
	char	*map_name;

	char	*addr;
	int		bpp;
	int		line_len;
	int		end;

	int		tile_size;
	float	mode;

	int		col;
	int		row;
	int		offset_x;
	int		offset_y;
	int		**tab;

	float	z_scale;	
	double	angle_h;
	double	angle_v;
}	t_info;

typedef struct s_dot
{
	float	screen_bx;
	float	screen_by;
	float	screen_ex;
	float	screen_ey;
	int		flag_x;
	int		flag_y;
	float	distance;
	float	step_x;
	float	step_y;
	int		screen_color;
	char	dir;
}	t_dot;

void	set_default(t_info *info, char *s);
void	matrix_init(t_info *info);
void	get_pixel(t_info *info, int x, int y, int color);
void	map_render(t_info *info);
void	put_desc(t_info *info);
void	recenter(t_info *info);
void	clear_image(t_info *info);

int		ft_isspace(char c);
int		ft_isvalidchar(char c);
void	ft_isvalidfd(char *s);

int		get_file_len(char *fdf_name);
int		set_color(t_info *info, int x, int y);

float	max_len(float x, float y);
void	get_distance(t_dot *dot);
void	get_render_info(t_info *info, t_dot *dot, char axis);

int		key_press(int keycode, t_info *info);
int		mouse_press(int mousecode, int x, int y, t_info *info);
int		close_window(t_info *info);

// message
void	error_msg_input_missing(void);
void	error_msg_invalid_fd(void);

#endif
