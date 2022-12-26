/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_xbm_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:32:46 by gresse            #+#    #+#             */
/*   Updated: 2022/12/26 02:46:21 by gresse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
#include <inttypes.h>

static void get_height_width_xbm(char *file_name, t_fdf *data)
{
    int     fd;
    char    *line;
    int     index;
    
    index = 0;
    fd = open(file_name, O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (index == 0)
            data->width = ft_atoi(ft_strrchr(line, ' '));
        if (index == 1)
            data->height = ft_atoi(ft_strrchr(line, ' '));
        free(line);
        if (!line)
            break ;
        index++;
    }
    close(fd);
}


static void browse_xbm_fill_matrix(char *file_name, t_fdf *data)
{
    int     fd;
    int     start;
    int     start_loop;
    int     index_y;
    int     index_x;
    char    *line;
    char    **nums;

    start_loop = 3;
	fd = open(file_name, O_RDONLY);
    while (start_loop-- > 0)
        line = get_next_line(fd);
	index_y = 0;
    start   = 0;
    while (index_y < 23)
    {
        index_x = 0;
        while (index_x < data->width)
        {
            line = get_next_line(fd);
            nums = ft_split(line, ' ');
            start = 0;
            while (nums[start])
                data->z_matrix[index_y][index_x++] = strtol(nums[start++], NULL, 0);
            free(nums);
            free(line);
        }
        index_y++;
    }
	close(fd);
}

void read_xbm_file(char *file_name, t_fdf *data)
{
    get_height_width_xbm(file_name, data);
    allocated_matrix(data);
    browse_xbm_fill_matrix(file_name, data);
}