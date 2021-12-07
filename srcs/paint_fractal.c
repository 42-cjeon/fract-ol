/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:21 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 14:54:37 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paint_fractal.h"

void	init_view(t_view *view)
{
	view->re_start = -1;
	view->re_end = 1;
	view->im_start = -1;
	view->im_end = 1;
}

void	scale_by_window(t_complex *c)
{
	t_complex	result;

	result.r = c->r / WINDOW_W;
	result.i = c->i / WINDOW_H;
	c->r = result.r;
	c->i = result.i;
}

void	scale_by_view(t_complex *c, t_view *view)
{
	c->r *= (view->re_end - view->re_start);
	c->r += view->re_start;
	c->i *= (view->im_end - view->im_start);
	c->i += view->im_start;
}

void	paint_fractal(unsigned int *img, t_fractal_func *ff, \
						t_view *view, t_color *color)
{
	t_complex		c;
	t_complex		z;
	int				w;
	int				h;
	int				time;

	h = 0;
	while (h < WINDOW_H)
	{
		w = 0;
		while (w < WINDOW_W)
		{
			c.r = w;
			c.i = h;
			scale_by_window(&c);
			scale_by_view(&c, view);
			ff->init_complex(&z, &c);
			time = ff->calc_time(&z, &c);
			*img++ = get_color(color, time);
			w++;
		}
		h++;
	}
}
