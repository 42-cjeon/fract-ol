/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:08:56 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/06 18:48:57 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <string.h>

typedef struct s_draw_fractal_arg
{
	t_fractal_func	*ff;
	t_image			*img;
	t_view			*view;
	void			*mlx;
	void			*win;

}	t_draw_fractal_arg;

int draw_fractal(t_draw_fractal_arg *arg)
{
	paint_fractal((unsigned int *)arg->img->addr, arg->ff, arg->view);
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

#define KB_Z 6
#define KB_X 7

#include <math.h>
#include <stdio.h>

int keyboard_hook(int code, t_view *view)
{
	double k;
	
	if (code == UP)
	{
		k = fabs(view->im_end - view->im_start) / 8;
		view->im_start -= k;
		view->im_end -= k;
	}
	else if (code == DOWN)
	{
		k = fabs(view->im_end - view->im_start) / 8;
		view->im_start += k;
		view->im_end += k;
	}
	else if (code == LEFT)
	{
		k = fabs(view->re_end - view->re_start) / 8;
		view->re_start -= k;
		view->re_end -= k;
	}
	else if (code == RIGHT)
	{
		k = fabs(view->re_end - view->re_start) / 8;
		view->re_start += k;
		view->re_end += k;
	}
	else if (code == KB_X)
	{
		k = fabs(view->re_end - view->re_start) / 8;
		view->re_start -= k;
		view->re_end += k;
		k = fabs(view->im_end - view->im_start) / 8;
		view->im_start -= k;
		view->im_end += k;
	}
	else if (code == KB_Z)
	{
		k = fabs(view->re_end - view->re_start) / 8;
		view->re_start += k;
		view->re_end -= k;
		k = fabs(view->im_end - view->im_start) / 8;
		view->im_start += k;
		view->im_end -= k;
	}
	printf("[-] CURR-POS rs=%lf re=%lf is=%lf ie=%lf\n", view->re_start, view->re_end, view->im_start, view->im_end);
	return 0;
}

void display_fractal(t_fractal_func *ff)
{
	void		*mlx;
	void		*win;
	t_view		view;
	t_image		img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_W, WINDOW_H, "TEST");
	init_view(&view);
	img.img = mlx_new_image(mlx, WINDOW_W, WINDOW_H);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.width, &img.endian);
	mlx_loop_hook(mlx, draw_fractal, &(t_draw_fractal_arg){ff, &img, &view ,mlx, win});
	mlx_key_hook(win, keyboard_hook, &view);
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