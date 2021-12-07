/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 02:20:10 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 15:00:02 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard_handler.h"

void	handle_move(int code, t_view *view)
{
	double	k;
	double	*target_axis_start;
	double	*target_axis_end;

	if (code == KB_ARROW_UP || code == KB_ARROW_DOWN)
	{
		target_axis_start = &view->im_start;
		target_axis_end = &view->im_end;
	}
	else
	{
		target_axis_start = &view->re_start;
		target_axis_end = &view->re_end;
	}
	k = fabs(*target_axis_end - *target_axis_start) / 10;
	if (code == KB_ARROW_RIGHT || code == KB_ARROW_DOWN)
	{
		*target_axis_start += k;
		*target_axis_end += k;
	}
	else
	{
		*target_axis_start -= k;
		*target_axis_end -= k;
	}
}

void	handle_color(int code, t_color *color)
{
	if (code == KB_NUMPAD_7)
		color->shift = circle_sub(color->shift, 10, 360);
	else if (code == KB_NUMPAD_9)
		color->shift = circle_add(color->shift, 10, 360);
	else if (code == KB_NUMPAD_4)
		color->saturation = fcircle_sub(color->saturation, 0.1, 1);
	else if (code == KB_NUMPAD_6)
		color->saturation = fcircle_add(color->saturation, 0.1, 1);
	else if (code == KB_NUMPAD_1)
		color->deg = circle_sub(color->deg, 10, 360);
	else if (code == KB_NUMPAD_3)
		color->deg = circle_add(color->deg, 10, 360);
}

int	keyboard_hook(int code, t_df_arg *arg)
{
	if (code == KB_ARROW_UP || code == KB_ARROW_DOWN \
			|| code == KB_ARROW_LEFT || code == KB_ARROW_RIGHT)
	{
		handle_move(code, arg->view);
		display_fractal(arg);
	}
	else if (code == KB_NUMPAD_1 || code == KB_NUMPAD_3 \
				|| code == KB_NUMPAD_4 || code == KB_NUMPAD_6 \
				|| code == KB_NUMPAD_7 || code == KB_NUMPAD_9)
	{
		handle_color(code, arg->color);
		display_fractal(arg);
	}
	else if (code == KB_ESC)
		exit(0);
	return (0);
}
