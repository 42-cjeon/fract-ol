/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:01:16 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/06 19:37:30 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_complex.h"

void	init_julia(t_complex *c, t_complex *z)
{
	c->r = -0.4;
	c->i = 0.6;
	(void)z;
}

void	init_mandelbrot(t_complex *z, t_complex *c)
{
	z->i = 0;
	z->r = 0;
	(void)c;
}

void	init_burningship(t_complex *z, t_complex *c)
{
	z->i = 0;
	z->r = 0;
	(void)c;
}
