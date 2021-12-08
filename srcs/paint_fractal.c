/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:21 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/08 00:36:02 by cjeon            ###   ########.fr       */
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

typedef struct s_paint_part_arg
{
	unsigned int *img;
	int from;
	int to;
	t_fractal_func *ff;
	t_view *view;
	t_color *color;
}	t_paint_part_arg;

#include <unistd.h>
#include <stdio.h>
void	*paint_fractal_part(void *v_arg)
{
	t_paint_part_arg *arg;
	t_complex c;
	t_complex z;
	int time;

	arg = (t_paint_part_arg *)v_arg;
	for (int i = arg->from; i < arg->to; i++) {
		for (int j = 0; j < WINDOW_W; j++) {
			c.i = i; c.r = j;
			scale_by_window(&c);
			scale_by_view(&c, arg->view);
			arg->ff->init_complex(&z, &c);
			time = arg->ff->calc_time(&z, &c);
			arg->img[i * WINDOW_W + j] = get_color(arg->color, time);
		}
	}
	return (NULL);
}

void	paint_fractal(unsigned int *img, t_fractal_func *ff, \
						t_view *view, t_color *color)
{
	pthread_t threads[N_THREADS];
	int tasks;
	int current_task;
	void *ret;

	tasks = WINDOW_H / (N_THREADS - 1);
	current_task = 0;
	for (int i = 0; i < N_THREADS - 1; i++) {
		if (pthread_create(threads + i, NULL, paint_fractal_part, &(t_paint_part_arg){img, current_task, current_task + tasks, ff, view, color}) < 0)
			exit(100);
		current_task += tasks;
	}
	if (pthread_create(threads + N_THREADS - 1, NULL, paint_fractal_part, &(t_paint_part_arg){img, current_task, WINDOW_H, ff, view, color}) < 0)
		exit(42);
	for (int i = 0; i < N_THREADS; i++)
		pthread_join(threads[i], &ret);
}
