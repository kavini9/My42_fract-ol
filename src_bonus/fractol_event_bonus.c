/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:12:55 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/11 21:05:21 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ctrl(mlx_key_data_t keydata, void *param)
{
	t_fractol	*frac;

	frac = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(frac -> mlx, frac -> img);
		mlx_close_window(frac -> mlx);
		return ;
	}
	else if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
		control_guide();
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		set_color(frac);
		set_viewport(frac);
	}
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_ADD)
		&& frac -> max_iter < 500)
		frac -> max_iter += 5 ;
	else if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_SUBTRACT)
		&& frac -> max_iter > 10)
		frac->max_iter -= 5;
	else
		return;
	fractol_render(&(*frac));
}

void	zoom(double xdelta, double ydelta, void *param)
{
	int32_t		pix_x;
	int32_t		pix_y;
	double		zoom_fac;
	t_coord		mouse;
	t_fractol	*frac;

	(void)xdelta;
	frac = (t_fractol *)param;
	mlx_get_mouse_pos(frac -> mlx, &pix_x, &pix_y);
	pix_to_cmplex(pix_x, pix_y, &mouse, frac);
	if (ydelta > 0)
		zoom_fac = 0.9;
	else if (ydelta < 0)
		zoom_fac = 1.1;
	else
		return ;
	frac -> min.x = mouse.x + (frac -> min.x - mouse.x) * zoom_fac;
	frac -> max.x = mouse.x + (frac -> max.x - mouse.x) * zoom_fac;
	frac -> min.y = mouse.y + (frac -> min.y - mouse.y) * zoom_fac;
	frac -> max.y = mouse.y + (frac -> max.y - mouse.y) * zoom_fac;
	fractol_render(&(*frac));
}

void	shift(void *param)
{
	double		x_shift_fac;
	double		y_shift_fac;
	double		xrange;
	double		yrange;
	t_fractol	*frac;

	frac = (t_fractol *)param;
	xrange = frac -> max.x - frac -> min.x;
	yrange = frac -> max.y - frac -> min.y;
	if (mlx_is_key_down(frac -> mlx, MLX_KEY_RIGHT))
		x_shift_fac = 0.025;
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_LEFT))
		x_shift_fac = -0.025;
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_UP))
		y_shift_fac = 0.025;
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_DOWN))
		y_shift_fac = -0.025;
	else
		return ;
	frac -> min.x += xrange * x_shift_fac;
	frac -> max.x += xrange * x_shift_fac;
	frac -> min.y += yrange * y_shift_fac;
	frac -> max.y += yrange * y_shift_fac;
	fractol_render(&(*frac));
}

void color(void *param)
{
    t_fractol *frac;

    frac = (t_fractol *)param;
    if (mlx_is_key_down(frac -> mlx, MLX_KEY_H) &&
        mlx_is_key_down(frac -> mlx, MLX_KEY_LEFT_SHIFT) &&
        frac -> pix.h < 360.0)
        frac -> pix.h += 1;
    else if (mlx_is_key_down(frac -> mlx, MLX_KEY_H) && frac -> pix.h > 0)
        frac -> pix.h -= 1;
    else if (mlx_is_key_down(frac -> mlx, MLX_KEY_S) &&
             mlx_is_key_down(frac -> mlx, MLX_KEY_LEFT_SHIFT) &&
             frac -> pix.s < 1.0)
        frac -> pix.s += 0.1;
    else if (mlx_is_key_down(frac -> mlx, MLX_KEY_S) && frac -> pix.s > 0.0)
        frac -> pix.s -= 0.1;
    else if (mlx_is_key_down(frac -> mlx, MLX_KEY_V) &&
             mlx_is_key_down(frac -> mlx, MLX_KEY_LEFT_SHIFT) &&
             frac -> pix.v < 1.0)
        frac -> pix.v += 0.1;
    else if (mlx_is_key_down(frac -> mlx, MLX_KEY_V) && frac -> pix.v > 0.0)
        frac -> pix.v -= 0.1;
    else
        return;
    fractol_render(frac);
}

