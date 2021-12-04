#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct s_image
{
	void *img;
	void *addr;
	int bpp;
	int width;
	int endian;

}	t_image;

typedef struct s_color
{
	unsigned int T : 8;
	unsigned int R : 8;
	unsigned int G : 8;
	unsigned int B : 8;
} t_color;

typedef struct s_complex
{
	long double r;
	long double i;
} t_complex;

/* !START */

static inline long long complex_dist(t_complex c)
{
	return (c.r * c.r + c.i * c.i);
}

static inline t_complex complex_square(t_complex c)
{
	t_complex temp;

	temp.r = (c.r * c.r) - (c.i * c.i);
	temp.i = 2 * (c.r * c.i);

	return temp;
}

static inline t_complex complex_add(t_complex x, t_complex y)
{
	x.r += y.r;
	x.i += y.i;
	return (x);
}

#define MAX_STEP 1000

int is_in_set(t_complex c)
{
	t_complex z;
	int i;

	z.r = 0;
	z.i = 0;
	i = 0;
	while (i < MAX_STEP && complex_dist(z) < 4LL)
	{
		z = complex_add(complex_square(z), c);
		i++;
	}
	return i;
}

#define RE_START -1.8
#define RE_END -1.725
#define IM_START -0.05
#define IM_END 0.01
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int is_in_set2(t_complex c, t_complex z)
{
	int i;

	i = 0;
	while (i < MAX_STEP && complex_dist(z) < 4LL)
	{
		z = complex_add(complex_square(z), c);
		i++;
	}
	return i;
}

void paint_julia_set(t_image *img)
{
	unsigned int *p_img;
	long double re;
	long double im;
	int			iter;
	p_img = (unsigned int *)img->addr;
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
	{
		re = (i % WINDOW_WIDTH) / (long double)WINDOW_WIDTH;
		im = (i / WINDOW_WIDTH) / (long double)WINDOW_HEIGHT;
		re *= ((long double)RE_END - RE_START);
		re += (long double)RE_START;
		im *= ((long double)IM_END - IM_START);
		im += (long double)IM_START;
		iter = is_in_set2((t_complex){-0.4, 0.6}, (t_complex){re, im});
		p_img[i] = (unsigned int)((double)(MAX_STEP - iter) / MAX_STEP * 0xFFFFFF);
	}
}

void paint_mandelbrot_set(t_image *img)
{
	unsigned int *p_img;
	long double re;
	long double im;
	int			iter;
	p_img = (unsigned int *)img->addr;
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
	{
		re = (i % WINDOW_WIDTH) / (long double)WINDOW_WIDTH;
		im = (i / WINDOW_WIDTH) / (long double)WINDOW_HEIGHT;
		re *= (RE_END - RE_START);
		re += RE_START;
		im *= (IM_END - IM_START);
		im += IM_START;
		iter = is_in_set((t_complex){re, im});
		p_img[i] = (unsigned int)((double)(MAX_STEP - iter) / MAX_STEP * 0xFFFFFF);
	}
}

int is_in_set3(t_complex c)
{
	t_complex z;

	int i;

	z.i = 0;
	z.r = 0;
	i = 0;
	while (i < MAX_STEP && complex_dist(z) < 4LL)
	{
		z = complex_add(complex_square((t_complex){fabsl(z.r), fabsl(z.i)}), c);
		i++;
	}
	return i;
}

void paint_burning_ship(t_image *img)
{
	unsigned int *p_img;
	long double re;
	long double im;
	int			iter;
	p_img = (unsigned int *)img->addr;
	for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++)
	{
		re = (i % WINDOW_WIDTH) / (long double)WINDOW_WIDTH;
		im = (i / WINDOW_WIDTH) / (long double)WINDOW_HEIGHT;
		re *= (RE_END - RE_START);
		re += RE_START;
		im *= (IM_END - IM_START);
		im += IM_START;
		iter = is_in_set3((t_complex){re, im});
		p_img[i] = (unsigned int)((double)(MAX_STEP - iter) / MAX_STEP * 0xFFFFFF);
	}
}

/* !END */

int main(void)
{
	void		*mlx;
	void		*win;
	t_image		img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "TEST");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.width, &img.endian);
	//paint_julia_set(&img);
	paint_burning_ship(&img);
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);

	return 0;
}