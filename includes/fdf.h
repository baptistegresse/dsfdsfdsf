/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 00:15:59 by gresse            #+#    #+#             */
/*   Updated: 2022/12/23 14:57:18 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>

# define LEFT_ARROW 124
# define RIGHT_ARROW 123
# define UP_ARROW 125
# define DOWN_ARROW 126
# define ZOOM_IN_KEY 34
# define ZOOM_OUT_KEY 31
# define A_KEY 1
# define W_KEY 2
# define S_KEY 0
# define D_KEY 13
# define B_KEY 11
# define ESC_KEY 53
# define ON_DESTROY 17
# define H_KEY 4
# define WIN_W 2000
# define WIN_H 2000

typedef struct s_fdf
{
	float	x;
	float	y;
	int		z;
	int		z1;

	int		width;
	int		height;
	int		**z_matrix;

	int		zoom;
	int		color;
	int		travel_l;
	int		travel_r;
	float	rotation_r;
	float	rotation_l;
	int		two_dimension;
	int		side_dimension;

	void	*mlx_ptr;
	void	*win_ptr;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_fdf;

void	read_file(char *file_name, t_fdf *data);
void	bresenham(float x1, float y1, t_fdf data);
void	draw(t_fdf *data);

int		close_window(t_fdf *data);
int		deal_key(int keycode, t_fdf *data);
void	moove_camera(int keycode, t_fdf *data);
void	free_tab(t_fdf *data);

int		max1(int a, int b);
float	mod(float index);
void	isometric(float *x, float *y, int z, t_fdf data);
void	zoom_value(float *x1, float *y1, t_fdf *data);

int		choose_color(int z, int z1);
int		choose_color(int z, int z1);
void	zoom_camera(int keycode, t_fdf *data);
void	reset_rotation(t_fdf *data);
void	moove_camera(int keycode, t_fdf *data);
void	rotation_fdf(int keycode, t_fdf *data);

#endif
