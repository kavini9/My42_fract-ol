/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:48:57 by wweerasi          #+#    #+#             */
/*   Updated: 2024/10/30 14:55:09 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
//pointer referncing in chaos.

void	pix_to_cmplex(int x, int y, t_coord *p, t_coord min, t_coord max)
{
	p -> x = min.x + (max.x - min.x) / WIDTH * x;
	p -> y = max.y - (max.x - min.x) / HEIGHT * y;
}

void	escape_count(t_fractol *frac)
{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	tmp_zx;

	zx = frac->z.x;
	zy = frac->z.y;
	cx = frac->c.x;
	cy = frac->c.y;
	frac->n = 0;
	while ((zx * zx) + (zy * zy) < 4.0 && frac->n < MAX_ITER)
	{
		tmp_zx = (zx * zx) - (zy * zy) + cx;
		zy = 2 * zx * zy + cy;
		zx = tmp_zx;
		frac->n++;
	}
}

void	julia(int x, int y, t_fractol *frac)
{
	double tmp_zx;

	frac -> n = 0;
	pix_to_cmplex(x, y, &(frac -> z), frac -> min, frac -> max);
	escape_count(frac);
	get_color(&(frac -> pix), frac -> n);
}

void	mandelbrot(int x, int y, t_fractol *frac)
{
	double tmp_zx;
	
	frac -> z.x = 0;
	frac -> z.y = 0;
	frac -> n = 0;
	pix_to_cmplex(x, y, &(frac -> c), frac -> min, frac -> max);
	escape_count(frac);
	get_color(&(frac -> pix), frac -> n);
}

void	fractol_render(t_fractol *frac)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (!ft_strcmp(frac -> f_set, "julia"))
				julia(x, y, frac);
			if (!ft_strcmp(frac -> f_set, "mandelbrot"))
				mandelbrot(x, y, frac);
			mlx_put_pixel(frac-> img, x, y, frac -> pix.color);
			y++;
		}
		x++;
	}
	mlx_image_to_window(frac -> mlx, frac -> img, 0, 0);
}
