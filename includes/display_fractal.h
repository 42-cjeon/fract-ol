/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_fractal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:20:43 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/07 15:00:03 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_FRACTAL_H
# define DISPLAY_FRACTAL_H

# include "coloring.h"
# include "mlx.h"
# include "paint_fractal.h"

typedef struct s_image
{
	void	*img;
	void	*addr;
	int		bpp;
	int		width;
	int		endian;
}	t_image;

typedef struct s_draw_fractal_arg
{
	t_fractal_func	*ff;
	t_image			*img;
	t_view			*view;
	t_color			*color;
	void			*mlx;
	void			*win;

}	t_df_arg;

int	display_fractal(t_df_arg *arg);

#endif