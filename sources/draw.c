/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:34:17 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/23 15:31:27 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw(t_fdf *data)
{
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			if (data->x < data->width - 1)
				bresenham(data->x + 1, data->y, *data);
			if (data->y < data->height - 1)
				bresenham(data->x, data->y + 1, *data);
			data->x++;
		}
		data->y++;
	}
}
