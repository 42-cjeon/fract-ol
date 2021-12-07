/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:47:14 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 14:01:34 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

int		complex_dist(const t_complex *c);
void	complex_square(t_complex *c);
void	complex_add(t_complex *x, t_complex *y);

#endif