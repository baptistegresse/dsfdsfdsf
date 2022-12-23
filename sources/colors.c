/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:24:16 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/24 00:14:46 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	choose_color(int z, int z1)
{
	if (z || z1)
	{
		if (z < 2 || z1 < 2)
			return (44444444);
		else if (z < 5 || z1 < 5)
			return (88888888);
		else if (z < 10 || z1 < 10)
			return (11111111);
		else if (z < 20 || z1 < 20)
			return (22222222);
		else if (z < 50 || z1 < 50)
			return (33333333);
		else if (z < 70 || z1 < 70)
			return (77777777);
		else if (z < 100 || z1 < 100)
			return (77777777);
		else if (z > -5 || z1 > -5)
			return (99999999);
		else if (z > -10 || z1 > -10)
			return (938597534);
		else if (z > -20 || z1 > -20)
			return (65625436);
	}
	return (3333333);
}
