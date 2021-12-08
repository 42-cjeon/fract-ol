/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:21 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/08 15:17:10 by cjeon            ###   ########.fr       */
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
#include <string.h>
#include <errno.h>
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
	t_paint_part_arg arg[N_THREADS];
	int tasks;
	int current_task;
	int ret;

	tasks = WINDOW_H / (N_THREADS - 1);
	current_task = 0;
	for (int i = 0; i < N_THREADS - 1; i++) {
		arg[i].img = img;
		arg[i].ff = ff;
		arg[i].view = view;
		arg[i].color = color;
		arg[i].from = current_task;
		current_task += tasks;
		arg[i].to = current_task;
		if ((ret = pthread_create(threads + i, NULL, paint_fractal_part, arg + i))) {
			perror(strerror(ret));
			exit(ret);
		}
	}
	arg[N_THREADS - 1].img = img;
	arg[N_THREADS - 1].ff = ff;
	arg[N_THREADS - 1].view = view;
	arg[N_THREADS - 1].color = color;
	arg[N_THREADS - 1].from = WINDOW_H - (WINDOW_H % (N_THREADS - 1));
	arg[N_THREADS - 1].to = WINDOW_H;
	if ((ret = pthread_create(threads + N_THREADS - 1, NULL, paint_fractal_part, arg + N_THREADS - 1))) {
		perror(strerror(ret));
		exit(ret);
	}
	for (int i = 0; i < N_THREADS; i++) {
		if ((ret = pthread_join(threads[i], NULL))) {
			perror(strerror(ret));
			exit(ret);
		}
	}
}
