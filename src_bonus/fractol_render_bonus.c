/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:48:57 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/26 18:00:32 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	pix_to_cmplex(int x, int y, t_coord *p, t_fractol *frac)
{
	p -> x = frac -> min.x + (frac -> max.x - frac -> min.x) / WIDTH * x;
	p -> y = frac -> max.y - (frac -> max.y - frac -> min.y) / HEIGHT * y;
}

static void	escape_count(t_fractol *frac)
{
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	tmp;

	zx = frac -> z.x;
	zy = frac -> z.y;
	cx = frac -> c.x;
	cy = frac -> c.y;
	while ((zx * zx) + (zy * zy) < 10.0 && frac -> n < frac -> max_iter)
	{
		tmp = (zx * zx) - (zy * zy) + cx;
		if (!ft_strcmp(frac -> f_set, "burning_ship"))
			zy = 2 * fabs(zx * zy) - cy;
		else
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
	frac -> mu = 0;
	pix_to_cmplex(x, y, &(frac -> z), frac);
	escape_count(frac);
	get_color(frac, frac -> n, frac -> mu);
}

static void	mandel_n_ship(int x, int y, t_fractol *frac)
{
	frac -> z.x = 0;
	frac -> z.y = 0;
	frac -> n = 0;
	frac -> mu = 0;
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
			if (!ft_strcmp(frac -> f_set, "mandelbrot")
				||!ft_strcmp(frac -> f_set, "burning_ship"))
				mandel_n_ship(x, y, frac);
			mlx_put_pixel(frac-> img, x, y, frac -> pix.color);
			y++;
		}
		x++;
	}
	mlx_image_to_window(frac -> mlx, frac -> img, 0, 0);
}
