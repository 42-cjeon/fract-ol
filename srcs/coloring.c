/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:56:34 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/06 21:30:58 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

unsigned int hsv_to_rgb(int h, double s, double v)
{
	double	c;
	double	x;
	double	m;
	
	h %= 360;
	c = s * v;
	x = c * (1 - abs(h / 60  % 2 - 1));
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

unsigned int get_color(int from, int deg, int time)
{
	if (time == MAX_ITER)
		return 0;
	return hsv_to_rgb(from + deg * time / (double)MAX_ITER, 0.2, time / (double)MAX_ITER);
	//return ((double)(MAX_ITER - time) / MAX_ITER * 0xFFFFFF);
}