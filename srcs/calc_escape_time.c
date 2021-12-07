/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_escape_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:41:10 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 14:11:41 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc_escape_time.h"

int	calc_mandelbrot_time(t_complex *z, t_complex *c)
{
	int	i;

	i = 0;
	while (i < MAX_ITER && complex_dist(z) < 4)
	{
		complex_square(z);
		complex_add(z, c);
		i++;
	}
	return (i);
}

int	calc_julia_time(t_complex *c, t_complex *z)
{
	int	i;

	i = 0;
	while (i < MAX_ITER && complex_dist(z) < 4)
	{
		complex_square(z);
		complex_add(z, c);
		i++;
	}
	return (i);
}

int	calc_burningship_time(t_complex *z, t_complex *c)
{
	int	i;

	i = 0;
	while (i < MAX_ITER && complex_dist(z) < 4)
	{
		z->i = fabs(z->i);
		z->r = fabs(z->r);
		complex_square(z);
		complex_add(z, c);
		i++;
	}
	return (i);
}
