/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchetana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 03:04:54 by cchetana          #+#    #+#             */
/*   Updated: 2022/06/16 03:05:57 by cchetana         ###   ########.fr       */
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

// ----- DEFAULT RESOLUTION ----- //
# define WIDTH_WIN 1500
# define HEIGHT_WIN 800

// ----- FOR KEYBOARD EVENT ----- //
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
# define RESET_KEY 15
# define TWOD_KEY 19
# define THREED_KEY 20

// ----- FOR MOUSE EVENT ----- //
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
	char	*map_name;

	void	*img_ptr;
	char	*img_px_addr;
	int		bpp;
	int		line_len;
	int		end;

	int		tile_size;
	float	mode;

	int		col;
	int		row;
	int		offset_x;
	int		offset_y;
	int		accum_x;
	int		accum_y;

	int		**tab;
	int		**tabc;

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
	float	tmp_x;
	float	tmp_y;
	int		flag_x;
	int		flag_y;
	float	distance;
	float	step_x;
	float	step_y;
	int		screen_color;
	char	dir;
}	t_dot;

typedef struct s_counter
{
	int		x;
	int		y;
	int		i;
	char	*tmp;
}	t_counter;

// ----- SET INFORMATION ----- //
// ----- GENERAL ----- //
void	set_info(t_info *info, char *s);
void	reset_info(t_info *info);
void	fdf_instruction(t_info *info);
int		get_file_len(char *fdf_name);

// ----- MATRIX ----- //
void	matrix_init(t_info *info);
void	matrix_realloc_info(t_info *info);
void	matrix_realloc_color(t_info *info);
int		loop_matrix(char *s);
int		get_hex_index(char c);
int		get_matrix_color(t_info *info, t_counter *t, int index);

// ----- RENDER ----- //
float	max_len(float x, float y);
void	get_distance(t_dot *dot);
void	get_render_info(t_info *info, t_dot *dot, char axis);
void	get_pixel(t_info *info, int x, int y, int color);
void	recenter(t_info *info);
void	map_render(t_info *info);
void	clear_image(t_info *info);
int		set_color(t_info *info, t_dot *dot, int x, int y);

// ----- VALID CHECKER ----- //
int		ft_isspace(char c);
int		ft_isvalidchar(char c);
int		ft_ishex(char *s);
void	ft_isvalidfd(char *s);

// ----- EVENT ----- //
int		key_press(int keycode, t_info *info);
int		mouse_press(int mousecode, int x, int y, t_info *info);

// ----- ERROR MESSAGE ----- //
void	error_msg_invalid_input(void);
void	error_msg_mlx(t_info *info);
void	error_msg_img(t_info *info);
void	error_msg_matrix_info(t_info *info, int index);
void	error_msg_matrix_color(t_info *info, int index);

// ----- FREE ----- //
void	free_mlx_win(t_info *info);
void	free_img(t_info *info);
void	free_matrix_info(t_info *info, int index);
void	free_matrix_color(t_info *info, int index);
int		close_window(t_info *info);

#endif
