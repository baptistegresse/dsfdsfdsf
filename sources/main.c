/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:31:34 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/26 02:39:45 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static void	init_struct(t_fdf *data)
{
	data->height = 0;
	data->width = 0;
	data->zoom = 4;
	data->x = 0;
	data->y = 0;
	data->color = 0;
	data->travel_l = 400;
	data->travel_r = 100;
	data->rotation_l = 0.8;
	data->rotation_r = 0.8;
	data->two_dimension = 1;
	data->side_dimension = 0;
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2 || open(argv[1], O_RDONLY) < 0)
		return (0);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	init_struct(data);
	if (ft_strnstr(argv[1], ".fdf", ft_strlen(argv[1])))
		read_file(argv[1], data);
	if (ft_strnstr(argv[1], ".xbm", ft_strlen(argv[1])))
		read_xbm_file(argv[1], data);
	
	int i = 0;
	int j = 0;

	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}


	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_H, WIN_W, "FDF");
	data->img = mlx_new_image(data->mlx_ptr, 2000, 2000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	draw(data);
	mlx_hook(data->win_ptr, 17, 1l << 0, close_window, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_loop(data->mlx_ptr);
	return (free_tab(data), free(data->z_matrix), free(data), 0);
}
