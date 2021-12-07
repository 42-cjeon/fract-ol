/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:08:56 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 15:00:29 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	exit_helper(void *k)
{
	(void)k;
	exit(0);
	return (0);
}

void	check_null_exit(void *p)
{
	if (p != NULL)
		return ;
	write(2, "[!] ", 4);
	perror(strerror(errno));
	exit(1);
}

void	start_fractal(t_fractal_func *ff)
{
	void		*mlx;
	void		*win;
	t_color		color;
	t_view		view;
	t_image		img;

	mlx = mlx_init();
	check_null_exit(mlx);
	win = mlx_new_window(mlx, WINDOW_W, WINDOW_H, "Fract-ol");
	check_null_exit(win);
	init_view(&view);
	init_color(&color);
	img.img = mlx_new_image(mlx, WINDOW_W, WINDOW_H);
	check_null_exit(img.img);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.width, &img.endian);
	check_null_exit(img.addr);
	display_fractal(&(t_df_arg){ff, &img, &view, &color, mlx, win});
	mlx_hook(win, X11_KEYPRESS, X11_KEYPRESS_MASK | X11_BUTTONPRESS_MASK, \
				keyboard_hook, &(t_df_arg){ff, &img, &view, &color, mlx, win});
	mlx_hook(win, X11_BUTTONPRESS, X11_KEYPRESS_MASK | X11_BUTTONPRESS_MASK, \
				mouse_hook, &(t_df_arg){ff, &img, &view, &color, mlx, win});
	mlx_hook(win, X11_DESTROYNOTIFY, X11_NOMASK, exit_helper, NULL);
	mlx_loop(mlx);
}

int	parse_input(int argc, char **argv, \
					t_initf *init_complex, t_calc_timef *calc_time)
{
	if (argc < 2)
		return (FAILURE);
	if (ft_strcmp(argv[1], "-j") == 0)
	{
		*init_complex = init_julia;
		*calc_time = calc_julia_time;
		return (SUCCESS);
	}
	else if (ft_strcmp(argv[1], "-b") == 0)
	{
		*init_complex = init_burningship;
		*calc_time = calc_burningship_time;
		return (SUCCESS);
	}
	else if (ft_strcmp(argv[1], "-m") == 0)
	{
		*init_complex = init_mandelbrot;
		*calc_time = calc_mandelbrot_time;
		return (SUCCESS);
	}
	return (FAILURE);
}

int	main(int argc, char **argv)
{
	t_initf			init_complex;
	t_calc_timef	calc_time;

	if (parse_input(argc, argv, &init_complex, &calc_time) == FAILURE)
	{
		printf("Usage : ./fractol [-m | -j | -b]\n");
		return (1);
	}
	start_fractal(&(t_fractal_func){init_complex, calc_time});
	return (0);
}
