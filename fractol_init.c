/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:02:04 by wweerasi          #+#    #+#             */
/*   Updated: 2024/10/30 20:13:38 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	set_viewport(t_fractol *frac)
{
	if (!ft_strcmp(frac -> f_set, "julia"))
	{
		frac -> min.x = -2.0;
		frac -> min.y = -2.0;
		frac -> max.x = 2.0;
		frac -> max.y = 2.0;
	}
	else if (!ft_strcmp(frac -> f_set, "mandelbrot"))
	{
		frac -> min.x = -3.0;
		frac -> min.y = -2.5;
		frac -> max.x = 2.0;
		frac -> max.y = 2.5;
	}
}

static void	set_colors(t_fractol *frac)
{
	frac -> pix.red_base = 0.041;
	frac -> pix.green_base =0.082;
	frac -> pix.blue_base = 0.164;
}

static void	set_julia_c(t_fractol *frac, char **av)
{
	frac -> c.x = ft_atof(av[2]);
	frac -> c.y = ft_atof(av[3]);
	if ((frac -> c.x > 2.0 || frac -> c.x < -2.0) ||
			(frac -> c.y > 2.0 || frac -> c.y < -2.0))
	{
		arg_guide("Argument values are out of range.");
		mlx_terminate(frac -> mlx);
		exit(EXIT_FAILURE);
	}
}

void init_fractol(t_fractol *frac, char **av)
{
	frac -> f_set = av[1];
	frac -> mlx = mlx_init(WIDTH, HEIGHT, frac -> f_set, false);
	if (!(frac -> mlx))
		arg_guide("TEST");//mlx_error();//think about this later
	frac -> img = mlx_new_image(frac -> mlx, WIDTH, HEIGHT);
	if (!(frac -> img))
	{
		mlx_terminate(frac -> mlx);
		arg_guide("TEST");//mlx_error(); // think about this later
	}
	if (!(ft_strcmp(frac -> f_set,"julia")))
		set_julia_c(frac, av);
	set_viewport(frac);
	set_colors(frac);
	mlx_image_to_window(frac -> mlx, frac -> img, 0, 0);
}
