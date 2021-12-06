/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_complex.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:00:43 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/06 12:57:58 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_COMPLEX_H
# define INIT_COMPLEX_H

# include "ft_complex.h"

void	init_burningship(t_complex *z, t_complex *c);
void	init_julia(t_complex *z, t_complex *c);
void	init_mandelbrot(t_complex *z, t_complex *c);

#endif