/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:51:37 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/23 15:03:08 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom_camera(int keycode, t_fdf *data)
{
	if (keycode == ZOOM_OUT_KEY && data->zoom <= 3)
		return ;
	if (keycode == ZOOM_OUT_KEY)
		data->zoom--;
	if (keycode == ZOOM_IN_KEY)
		data->zoom++;
}

void	reset_rotation(t_fdf *data)
{
	data->rotation_l = 0.0;
	data->rotation_r = 0.0;
}

void	moove_camera(int keycode, t_fdf *data)
{
	if (keycode == RIGHT_ARROW)
		data->travel_l += 20;
	if (keycode == LEFT_ARROW)
		data->travel_l -= 20;
	if (keycode == UP_ARROW)
		data->travel_r -= 20;
	if (keycode == DOWN_ARROW)
		data->travel_r += 20;
}

void	rotation_fdf(int keycode, t_fdf *data)
{
	if (keycode == A_KEY)
		data->rotation_r += 0.10;
	if (keycode == D_KEY)
		data->rotation_r -= 0.10;
	if (keycode == W_KEY)
		data->rotation_l += 0.10;
	if (keycode == S_KEY)
		data->rotation_l -= 0.10;
}
