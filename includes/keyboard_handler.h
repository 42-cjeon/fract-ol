/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 02:20:31 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 15:00:02 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_HANDLER_H
# define KEYBOARD_HANDLER_H

# include <math.h>

# include "display_fractal.h"
# include "fract_ol.h"
# include "paint_fractal.h"
# include "utils.h"

# define KB_ARROW_UP 126
# define KB_ARROW_DOWN 125
# define KB_ARROW_LEFT 123
# define KB_ARROW_RIGHT 124
# define KB_NUMPAD_7 89
# define KB_NUMPAD_9 92
# define KB_NUMPAD_4 86
# define KB_NUMPAD_6 88
# define KB_NUMPAD_1 83
# define KB_NUMPAD_3 85
# define KB_ESC 53

int	keyboard_hook(int code, t_df_arg *arg);

#endif