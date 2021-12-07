/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:16:39 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 14:51:47 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include "constants.h"
# include "mlx.h"
# include "paint_fractal.h"
# include "keyboard_handler.h"
# include "mouse_handler.h"

# define X11_BUTTONPRESS 4
# define X11_KEYPRESS 2
# define X11_DESTROYNOTIFY 17

# define X11_NOMASK (0L)
# define X11_KEYPRESS_MASK (1L)
# define X11_BUTTONPRESS_MASK (4L)

enum e_result
{
	FAILURE,
	SUCCESS
};

#endif