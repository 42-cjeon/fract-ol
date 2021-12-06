/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:16:39 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/06 14:00:00 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "constants.h"
# include "mlx.h"
# include "paint_fractal.h"

typedef struct s_image
{
	void *img;
	void *addr;
	int bpp;
	int width;
	int endian;

}	t_image;

enum e_result
{
	FAILURE,
	SUCCESS
};

#endif