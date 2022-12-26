/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gresse <gresse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:24:16 by bgresse           #+#    #+#             */
/*   Updated: 2022/12/24 13:38:12 by gresse           ###   ########.fr       */
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
		else if ( z < 11 || z1 < 11)
			return 9021033;
		else if (z < 12 || z1 < 12)
			return (10938511);
		else if (z < 13 || z1 < 13)
			return 901923;
		else if (z < 14 || z1 < 14)
			return 928135420;
		else if (z < 15 || z1 < 15)
			return 3134525;
		else if (z < 16 || z1 < 16)
			return 3295810;
		else if (z < 17 || z1 < 17)
			return 1385925;
		else if (z < 18 || z1 < 18)
			return 3809199;
		else if (z < 19 || z1 < 19)
			return 29081384;
		else if (z < 20 || z1 < 20)
			return (22222222);
		else if (z < 21 || z1 < 21)
			return (23100005);
		else if (z < 22 || z1 < 22)
			return 982455245;
		else if (z < 23 || z1 < 23)
			return 9852525;
		else if (z < 24 || z1 < 24)
			return 9843452;
		else if (z < 25 || z1 < 25)
			return 93245;
		else if (z < 26 || z1 < 26)
			return 89284535;
		else if (z < 27 || z1 < 27)
			return 209842;
		else if (z < 28 || z1 < 28)
			return 2985211;
		else if (z < 29 || z1 < 29)
			return 134100424;
		else if (z < 30 || z1 < 30)
			return 424325;
		else if (z < 31 || z1 < 31)
			return 18452500;
		else if (z < 32 || z1 < 32)
			return 145194;
		else if (z < 33 || z1 < 33)
			return 13329501;
		else if (z < 34 || z1 < 34)
			return 9285245;
		else if (z < 35 || z1 < 35)
			return 98001314;
		else if (z < 36 || z1 < 36)
			return 29852452;
		else if (z < 37 || z1 < 37)
			return 2945825;
		else if (z < 38 || z1 < 38)
			return 2525235;
		else if (z < 50 || z1 < 50)
			return (33333333);
		else if (z < 60 || z1 < 60)
			return (22222222);
		else if (z < 65 || z1 < 65)
			return (96999996);
		else if (z < 70 || z1 < 70)
			return (77777777);
		else if (z < 100 || z1 < 100)
			return (77777777);
		else if (z < 110 || z1 < 110)
			return (34542231);
		else if (z < 120 || z1 < 120)
			return (9968854);
		else if (z < 130 || z1 < 130)
			return (28811334);
		else if (z < 150 || z1 < 150)
			return (99421290);
		else if (z < 160 || z1 < 160)
			return (3112334);
		else if (z < 170 || z1 < 170)
			return (77771234);
		else if (z < 180 || z1 < 180)
			return (764729134);
		else if (z < 190 || z1 < 190)
			return (63747245);
		else if (z < 200 || z1 < 200)
			return 13343242;
		else if (z < 240 || z1 < 240)
			return 324252;
		else if (z < 248 || z1 < 248)
			return (3414145);
		else if (z < 249 || z1 < 249)
			return 1233414;
		else if (z < 250 || z1 < 250)
			return 7621100;
		else if (z < 251 || z1 < 251)
			return 93285285;
		else if ( z == 300 || z1 == 300)
			return (0);
		else if (z > -5 || z1 > -5)
			return (99999999);
		else if (z > -10 || z1 > -10)
			return (938597534);
		else if (z > -20 || z1 > -20)
			return (65625436);
	}
	return (3333333);
}
