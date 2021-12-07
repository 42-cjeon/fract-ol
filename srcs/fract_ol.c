/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:08:56 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 02:19:50 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <string.h>

typedef struct s_draw_fractal_arg
{
	t_fractal_func	*ff;
	t_image			*img;
	t_view			*view;
	t_color			*color;
	void			*mlx;
	void			*win;

}	t_draw_fractal_arg;

int draw_fractal(t_draw_fractal_arg *arg)
{
	paint_fractal((unsigned int *)arg->img->addr, arg->ff, arg->view, arg->color);
	mlx_put_image_to_window(arg->mlx, arg->win, arg->img->img, 0, 0);
	return 0;
}

void	init_view(t_view *view)
{
	view->re_start = -1;
	view->re_end = 1;
	view->im_start = -1;
	view->im_end = 1;
}

#define	UP          126
#define	DOWN        125
#define	LEFT        123
#define	RIGHT       124
#define ESC         53

#define KB_NUMPAD_7 89
#define KB_NUMPAD_9 92
#define KB_NUMPAD_4 86
#define KB_NUMPAD_6 88
#define KB_NUMPAD_1 83
#define KB_NUMPAD_3 85

#define KB_RIGHT_BRACKET 30
#define KB_LEFT_BRACKET 33
#define KB_ESC 53
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct s_keyboard_hook_arg
{
	t_view *view;
	t_color *color;
}	t_keyboard_hook_arg;

int keyboard_hook(int code, t_draw_fractal_arg *arg)
{
	double k;
	
	if (code == UP)
	{
		k = fabs(arg->view->im_end - arg->view->im_start) / 10;
		arg->view->im_start -= k;
		arg->view->im_end -= k;
	}
	else if (code == DOWN)
	{
		k = fabs(arg->view->im_end - arg->view->im_start) / 10;
		arg->view->im_start += k;
		arg->view->im_end += k;
	}
	else if (code == LEFT)
	{
		k = fabs(arg->view->re_end - arg->view->re_start) / 10;
		arg->view->re_start -= k;
		arg->view->re_end -= k;
	}
	else if (code == RIGHT)
	{
		k = fabs(arg->view->re_end - arg->view->re_start) / 10;
		arg->view->re_start += k;
		arg->view->re_end += k;
	}
	else if (code == KB_NUMPAD_7)
	{
		arg->color->shift -= 10;
		if (arg->color->shift < 0)
			arg->color->shift += 360;
	}
	else if (code == KB_NUMPAD_9)
	{
		arg->color->shift += 10;
		if (arg->color->shift >= 360)
			arg->color->shift -= 360;
	}
	else if (code == KB_NUMPAD_4)
	{
		arg->color->saturation -= 0.1;
		if (arg->color->saturation < 0)
			arg->color->saturation = 1;
	}
	else if (code == KB_NUMPAD_6)
	{
		arg->color->saturation += 0.1;
		if (arg->color->saturation > 1)
			arg->color->saturation = 0;
	}
	else if (code == KB_NUMPAD_1)
	{
		arg->color->deg -= 10;
		if (arg->color->deg < 0)
			arg->color->deg += 360;
	}
	else if (code == KB_NUMPAD_3)
	{
		arg->color->deg += 10;
		if (arg->color->deg > 360)
			arg->color->deg -= 360;
	}
	else if (code == KB_ESC)
		exit(0);
	draw_fractal(arg);
	return 0;
}

#define MS_SCROOL_DOWN 5
#define MS_SCROOL_UP 4
int mouse_hook(int code, int x, int y, t_draw_fractal_arg *arg)
{
	double k;

	if (code == MS_SCROOL_DOWN)
	{
		k = fabs(arg->view->re_end - arg->view->re_start) / 8;
		arg->view->re_start -= k * (x / (double)WINDOW_W);
		arg->view->re_end += k * ((WINDOW_W - x) / (double)WINDOW_W);
		k = fabs(arg->view->im_end - arg->view->im_start) / 8;
		arg->view->im_start -= k * (y / (double)WINDOW_H);
		arg->view->im_end += k * ((WINDOW_H - y) / (double)WINDOW_H);
	}
	else if (code == MS_SCROOL_UP)
	{
		k = fabs(arg->view->re_end - arg->view->re_start) / 8;
		arg->view->re_start += k * (x / (double)WINDOW_W);
		arg->view->re_end -= k * ((WINDOW_W - x) / (double)WINDOW_W);
		k = fabs(arg->view->im_end - arg->view->im_start) / 8;
		arg->view->im_start += k * (y / (double)WINDOW_H);
		arg->view->im_end -= k * ((WINDOW_H - y) / (double)WINDOW_H);
	}
	draw_fractal(arg);
	return 0;
}

#define X11_MOUSE_EVENT 4

int exit_helper(void *k)
{
	(void)k;
	exit(0);
	
	return 0;
}

void display_fractal(t_fractal_func *ff)
{
	void		*mlx;
	void		*win;
	t_color		color;
	t_view		view;
	t_image		img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_W, WINDOW_H, "TEST");
	init_view(&view);
	init_color(&color);
	img.img = mlx_new_image(mlx, WINDOW_W, WINDOW_H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.width, &img.endian);
	draw_fractal(&(t_draw_fractal_arg){ff, &img, &view, &color, mlx, win});
	mlx_hook(win, 2, 0,  keyboard_hook, &(t_draw_fractal_arg){ff, &img, &view, &color, mlx, win});
	mlx_hook(win, X11_MOUSE_EVENT, 0, mouse_hook, &(t_draw_fractal_arg){ff, &img, &view, &color, mlx, win});
	mlx_hook(win, 17, 0, exit_helper, NULL);
	mlx_loop(mlx);
}

int parse_input(int argc, char **argv, t_initf *init_complex, t_calc_timef *calc_time)
{
	if (argc < 2)
		return (FAILURE);
	if (strcmp(argv[1], "-j") == 0)
	{
		*init_complex = init_julia;
		*calc_time = calc_julia_time;
		return (SUCCESS);
	}
	else if (strcmp(argv[1], "-b") == 0)
	{
		*init_complex = init_burningship;
		*calc_time = calc_burningship_time;
		return (SUCCESS);
	}
	else if (strcmp(argv[1], "-m") == 0)
	{
		*init_complex = init_mandelbrot;
		*calc_time = calc_mandelbrot_time;
		return (SUCCESS);
	}
	return (FAILURE);
}

int main(int argc, char **argv)
{
	t_initf init_complex;
	t_calc_timef calc_time;

	if (parse_input(argc, argv, &init_complex, &calc_time) == FAILURE)
		return (1);
	display_fractal(&(t_fractal_func){init_complex, calc_time});
	return 0;
}