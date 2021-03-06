/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:30:27 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 14:02:45 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORING_H
# define COLORING_H

# include <math.h>
# include "constants.h"

typedef struct s_color
{
	int		shift;
	int		deg;
	double	saturation;
}	t_color;

unsigned int	get_color(t_color *color, int time);
unsigned int	hsv_to_rgb(int h, double s, double v);
void			init_color(t_color *color);

#endif