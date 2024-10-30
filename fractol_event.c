/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:12:55 by wweerasi          #+#    #+#             */
/*   Updated: 2024/10/30 20:11:07 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	esc(mlx_key_data_t keydata, void *param)
{
	t_fractol	*frac;

	frac = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(frac -> mlx, frac -> img);
		mlx_close_window(frac -> mlx);
	}
}

void zoom(double xdelta, double ydelta, void* param)
{
	int32_t		pix_x;
	int32_t		pix_y;
	double		zoom_fac;
	t_coord		mouse;
	t_fractol	*frac;

	(void)xdelta;
	frac = (t_fractol *)param;
	mlx_get_mouse_pos(frac -> mlx, &pix_x, &pix_y);
	pix_to_cmplex(pix_x, pix_y, &mouse, frac -> min, frac -> max);
	if (ydelta > 0)
		zoom_fac = 0.9;
	else if (ydelta < 0)
		zoom_fac = 1.1;
	else
		return;
	frac -> min.x = mouse.x + (frac -> min.x - mouse.x) * zoom_fac;
	frac -> max.x = mouse.x + (frac -> max.x - mouse.x) * zoom_fac;
	frac -> min.y = mouse.y + (frac -> min.y - mouse.y) * zoom_fac;
	frac -> max.y = mouse.y + (frac -> max.y - mouse.y) * zoom_fac;
	fractol_render(&(*frac));
}

void shift(void* param)
{
	double		shift_fac;
	double		xrange;
	double		yrange;
	t_fractol	*frac;

	frac = (t_fractol *)param;
	shift_fac = 0.025;
	xrange = frac -> max.x - frac -> min.x;
	yrange = frac -> max.y - frac -> min.y;
	if (mlx_is_key_down(frac -> mlx, MLX_KEY_RIGHT))
	{
		frac -> min.x += xrange * shift_fac;
		frac -> max.x += xrange * shift_fac;
	}
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_LEFT))
	{
		frac -> min.x -= xrange * shift_fac;
		frac -> max.x -= xrange * shift_fac;
	}
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_UP))
	{
		frac -> min.y += yrange * shift_fac;
		frac -> max.y += yrange * shift_fac;
	}
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_DOWN))
	{
		frac -> min.y -= yrange * shift_fac;
		frac -> max.y -= yrange * shift_fac;
	}else
		return;
	fractol_render(&(*frac));
}
		
