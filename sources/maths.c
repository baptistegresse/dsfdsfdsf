/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:21:48 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/23 15:08:33 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (y> WIN_H - 1 || x > WIN_W - 1 || x < 1 || y < 1)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	max1(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	mod(float index)
{
	if (index < 0)
		return (-index);
	return (index);
}

void	isometric(float *x, float *y, int z, t_fdf data)
{
	*x = (*x - *y) * cos(data.rotation_l);
	*y = (*x + *y) * sin(data.rotation_r) - z;
}

void	bresenham(float x1, float y1, t_fdf data)
{
	float	x_step;
	float	y_step;
	int		max;

	data.z = data.z_matrix[(int)data.y][(int)data.x];
	data.z1 = data.z_matrix[(int)y1][(int)x1];
	zoom_value(&x1, &y1, &data);
	data.color = choose_color(data.z, data.z1);
	if (data.two_dimension == 1)
	{
		isometric(&data.x, &data.y, data.z, data);
		isometric(&x1, &y1, data.z1, data);
	}
	x_step = x1 - data.x;
	y_step = y1 - data.y;
	max = max1(mod(x_step), mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(data.x - x1) || (int)(data.y - y1))
		my_mlx_pixel_put(&data, (data.x += x_step)
			+ data.travel_l, (data.y += y_step) + data.travel_r, data.color);
}

void	zoom_value(float *x1, float *y1, t_fdf *data)
{
	*x1 *= data->zoom;
	*y1 *= data->zoom;
	data->x *= data->zoom;
	data->y *= data->zoom;
}
