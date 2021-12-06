/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:50:06 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/06 11:44:09 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

int		complex_dist(const t_complex *c)
{
	return (c->r * c->r + c->i * c->i);
}

void	complex_square(t_complex *c)
{
	double im;
	double re;

	re = (c->r * c->r) - (c->i * c->i);
	im = (c->r * c->i) + (c->r * c->i);
	c->r = re;
	c->i = im;
}

void	complex_add(t_complex *x, t_complex *y)
{
	x->r += y->r;
	x->i += y->i;
}
