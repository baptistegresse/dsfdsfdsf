/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:15:23 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/23 14:57:40 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(t_fdf *data)
{
	free_tab(data);
	free(data->z_matrix);
	free(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

int	deal_key(int keycode, t_fdf *data)
{
	if (keycode == H_KEY)
		reset_rotation(data);
	if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW
		|| keycode == UP_ARROW || keycode == DOWN_ARROW)
		moove_camera(keycode, data);
	if (keycode == ZOOM_IN_KEY || keycode == ZOOM_OUT_KEY)
		zoom_camera(keycode, data);
	if (keycode == A_KEY || keycode == D_KEY
		|| keycode == W_KEY || keycode == S_KEY)
		rotation_fdf(keycode, data);
	if (keycode == B_KEY)
		data->two_dimension *= -1;
	if (keycode == ESC_KEY)
		exit(0);
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, 2000, 2000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	return (0);
}
