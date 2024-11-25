/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:12:55 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/24 20:45:30 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	prog_ctrls(mlx_key_data_t keydata, t_fractol *frac)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(frac -> mlx, frac -> img);
		mlx_close_window(frac -> mlx);
		ft_putendl_fd("Closed the window", 1);
		return ;
	}
	else if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
		return (control_guide());
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		frac -> max_iter = 100;
		set_color(frac);
		set_viewport(frac);
	}
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_KP_ADD)
		&& frac -> max_iter < 500)
		frac -> max_iter += 5 ;
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_KP_SUBTRACT)
		&& frac -> max_iter > 10)
		frac->max_iter -= 5;
	else
		return ;
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
	t_coord		shift_fac;
	double		xrange;
	double		yrange;
	t_fractol	*frac;

	frac = (t_fractol *)param;
	shift_fac.x = 0.0;
	shift_fac.y = 0.0;
	xrange = frac -> max.x - frac -> min.x;
	yrange = frac -> max.y - frac -> min.y;
	if (mlx_is_key_down(frac -> mlx, MLX_KEY_RIGHT))
		shift_fac.x = 0.025;
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_LEFT))
		shift_fac.x = -0.025;
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_UP))
		shift_fac.y = 0.025;
	else if (mlx_is_key_down(frac -> mlx, MLX_KEY_DOWN))
		shift_fac.y = -0.025;
	else
		return ;
	frac -> min.x += xrange * shift_fac.x;
	frac -> max.x += xrange * shift_fac.x;
	frac -> min.y += yrange * shift_fac.y;
	frac -> max.y += yrange * shift_fac.y;
	fractol_render(&(*frac));
}

static void	update_hsv(int key, double end, double step, t_fractol *frac)
{
	double	start;
	double	*hsv_comp;

	start = 0.01;
	if (key == MLX_KEY_H)
		hsv_comp = &(frac -> pix.h);
	else if (key == MLX_KEY_S)
		hsv_comp = &(frac -> pix.s);
	else if (key == MLX_KEY_V)
		hsv_comp = &(frac -> pix.v);
	if (mlx_is_key_down(frac -> mlx, key)
		&& mlx_is_key_down(frac -> mlx, MLX_KEY_LEFT_SHIFT)
		&& *hsv_comp < end)
		*hsv_comp += step;
	if (mlx_is_key_down(frac -> mlx, key)
		&& !mlx_is_key_down(frac -> mlx, MLX_KEY_LEFT_SHIFT)
		&& *hsv_comp > start)
		*hsv_comp -= step;
	set_palette(&(frac -> pix));
}

void	color_ctrls(mlx_key_data_t keydata, t_fractol *frac)
{
	if (keydata.key == MLX_KEY_H && keydata.action == MLX_PRESS)
		update_hsv(MLX_KEY_H, 360.0, 5.0, frac);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		update_hsv(MLX_KEY_S, .999, 0.100, frac);
	else if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
		update_hsv(MLX_KEY_V, .999, 0.100, frac);
	else
		return ;
	fractol_render(frac);
	ft_putstr_fd(" Color update:\t\tH\t\tS\t\tV\n\t\t\t", STDOUT_FILENO);
	ft_putflt_fd(frac -> pix.h, STDOUT_FILENO, 2);
	ft_putstr_fd("\t\t", STDOUT_FILENO);
	ft_putflt_fd(frac -> pix.s, STDOUT_FILENO, 2);
	ft_putstr_fd("\t\t", STDOUT_FILENO);
	ft_putflt_fd(frac -> pix.v, STDOUT_FILENO, 2);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
