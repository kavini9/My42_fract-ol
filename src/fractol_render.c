/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:40:01 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/26 12:08:29 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pix_to_cmplex(int x, int y, t_coord *p, t_fractol *frac)
{
	p -> x = frac -> min.x + (frac -> max.x - frac -> min.x) / WIDTH * x;
	p -> y = frac -> max.y - (frac -> max.x - frac -> min.x) / HEIGHT * y;
}

static void	escape_count(t_fractol *frac)
{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	tmp;

	zx = frac->z.x;
	zy = frac->z.y;
	cx = frac->c.x;
	cy = frac->c.y;
	frac -> n = 0;
	while ((zx * zx) + (zy * zy) < 4.0 && frac->n < frac -> max_iter)
	{
		tmp = (zx * zx) - (zy * zy) + cx;
		zy = 2 * zx * zy + cy;
		zx = tmp;
		frac -> n++;
	}
	tmp = fabs(sqrt(zx * zx + zy * zy));
	if (tmp > 1.0 && log(tmp) > 0.0)
		frac -> mu = frac->n - (log(log(tmp)) / log(2.0));
	else
		frac -> mu = 0.0;
}

static void	julia(int x, int y, t_fractol *frac)
{
	frac -> n = 0;
	pix_to_cmplex(x, y, &(frac -> z), frac);
	escape_count(frac);
	get_color(frac, frac -> n, frac -> mu);
}

static void	mandelbrot(int x, int y, t_fractol *frac)
{
	frac -> z.x = 0;
	frac -> z.y = 0;
	frac -> n = 0;
	pix_to_cmplex(x, y, &(frac -> c), frac);
	escape_count(frac);
	get_color(frac, frac -> n, frac -> mu);
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
