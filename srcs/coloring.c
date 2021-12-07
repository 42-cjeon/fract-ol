/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:56:34 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 01:58:20 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coloring.h"

unsigned int hsv_to_rgb(int h, double s, double v)
{
	double	c;
	double	x;
	double	m;

	h %= 360;
	c = s * v;
	x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
	m = v - c;
	if (h < 60)
		return (TORGB(c, m)<<16 | TORGB(x, m)<<8);
	else if (h < 120)
		return (TORGB(x, m)<<16 | TORGB(c, m)<<8);
	else if (h < 180)
		return (TORGB(c, m)<<8 | TORGB(x, m));
	else if (h < 240)
		return (TORGB(x, m)<<8 | TORGB(c, m));
	else if (h < 300)
		return (TORGB(x, m)<<16 | TORGB(c, m));
	else
		return (TORGB(c, m)<<16 | TORGB(x, m));
}

unsigned int get_color(t_color *color, int time)
{
	if (time == MAX_ITER)
		return 0;
	return hsv_to_rgb(color->shift + color->deg * time / (double)MAX_ITER, color->saturation, time / (double)MAX_ITER);
}

void init_color(t_color *color)
{
	color->deg = 0;
	color->shift = 0;
	color->saturation = 0.5;
}