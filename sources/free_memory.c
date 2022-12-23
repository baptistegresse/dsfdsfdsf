/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:53:43 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/20 17:54:59 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_tab(t_fdf *data)
{
	int		index;

	index = 0;
	while (index <= data->height)
		free(data->z_matrix[index++]);
}
