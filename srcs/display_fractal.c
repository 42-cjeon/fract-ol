/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:19:29 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/08 14:47:18 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_fractal.h"

int	display_fractal(t_df_arg *arg)
{
	paint_fractal((unsigned int *)arg->img->addr, \
					arg->ff, arg->view, arg->color);
	mlx_put_image_to_window(arg->mlx, arg->win, arg->img->img, 0, 0);
	return (0);
}
