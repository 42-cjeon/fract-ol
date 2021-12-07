/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:40:39 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 15:00:02 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse_handler.h"

int	mouse_hook(int code, int x, int y, t_df_arg *arg)
{
	double	k;

	if (code != MS_SCROOL_DOWN && code != MS_SCROOL_UP)
		return (0);
	if (code == MS_SCROOL_DOWN)
	{
		k = fabs(arg->view->re_end - arg->view->re_start) / 8;
		arg->view->re_start -= k * (x / (double)WINDOW_W);
		arg->view->re_end += k * ((WINDOW_W - x) / (double)WINDOW_W);
		k = fabs(arg->view->im_end - arg->view->im_start) / 8;
		arg->view->im_start -= k * (y / (double)WINDOW_H);
		arg->view->im_end += k * ((WINDOW_H - y) / (double)WINDOW_H);
	}
	else if (code == MS_SCROOL_UP)
	{
		k = fabs(arg->view->re_end - arg->view->re_start) / 8;
		arg->view->re_start += k * (x / (double)WINDOW_W);
		arg->view->re_end -= k * ((WINDOW_W - x) / (double)WINDOW_W);
		k = fabs(arg->view->im_end - arg->view->im_start) / 8;
		arg->view->im_start += k * (y / (double)WINDOW_H);
		arg->view->im_end -= k * ((WINDOW_H - y) / (double)WINDOW_H);
	}
	display_fractal(arg);
	return (0);
}
