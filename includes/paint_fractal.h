/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_fractal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:09:49 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/08 00:22:06 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAINT_FRACTAL_H
# define PAINT_FRACTAL_H

# include <pthread.h>
# include <stdlib.h>
# include "calc_escape_time.h"
# include "coloring.h"
# include "constants.h"
# include "complex.h"
# include "init_complex.h"

typedef void	(*t_initf)(t_complex *z, t_complex *c);
typedef int		(*t_calc_timef)(t_complex *c, t_complex* z);
typedef struct s_view
{
	double	re_start;
	double	re_end;
	double	im_start;
	double	im_end;
}				t_view;

typedef struct s_fractal_func
{
	t_initf			init_complex;
	t_calc_timef	calc_time;
}				t_fractal_func;

void	paint_fractal(unsigned int *img, t_fractal_func *ff, \
						t_view *view, t_color *color);
void	scale_by_view(t_complex *c, t_view *view);
void	scale_by_window(t_complex *c);
void	init_view(t_view *view);
#endif