/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_escape_time.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:53:47 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 13:59:00 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_ESCAPE_TIME_H
# define CALC_ESCAPE_TIME_H

# include "constants.h"
# include "ft_complex.h"
# include "math.h"

int	calc_mandelbrot_time(t_complex *z, t_complex *c);
int	calc_julia_time(t_complex *z, t_complex *c);
int	calc_burningship_time(t_complex *z, t_complex *c);

#endif