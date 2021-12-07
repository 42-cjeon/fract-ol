/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:44:03 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 15:00:02 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_HANDLER_H
# define MOUSE_HANDLER_H

# include "display_fractal.h"
# include "constants.h"

# define MS_SCROOL_DOWN 5
# define MS_SCROOL_UP 4

int	mouse_hook(int code, int x, int y, t_df_arg *arg);

#endif