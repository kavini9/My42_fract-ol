/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:02:04 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/26 17:58:47 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	set_color(t_fractol *frac)
{
	frac -> pix.h = 360.0;
	frac -> pix.s = 1.00;
	frac -> pix.v = 0.60;
	set_palette(&(frac -> pix));
}

void	set_viewport(t_fractol *frac)
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
	else if (!ft_strcmp(frac -> f_set, "burning_ship"))
	{
		frac -> min.x = -2.5;
		frac -> min.y = -1.5;
		frac -> max.x = 1.5;
		frac -> max.y = 2.5;
	}
}

static void	set_julia_c(t_fractol *frac, char **av)
{
	frac -> c.x = ft_atof(av[2]);
	frac -> c.y = ft_atof(av[3]);
	if ((frac -> c.x > 2.0 || frac -> c.x < -2.0)
		|| (frac -> c.y > 2.0 || frac -> c.y < -2.0))
	{
		arg_guide("Argument values are out of range.");
		exit(EXIT_FAILURE);
	}
}

void	init_fractol(t_fractol *frac, char **av)
{
	frac -> f_set = av[1];
	frac -> max_iter = 70;
	if (!(ft_strcmp(frac -> f_set, "julia")))
		set_julia_c(frac, av);
	frac -> mlx = mlx_init(WIDTH, HEIGHT, frac -> f_set, false);
	if (!(frac -> mlx))
	{
		error_out("MLX42 inizialization failed.");
		exit(EXIT_FAILURE);
	}
	frac -> img = mlx_new_image(frac -> mlx, WIDTH, HEIGHT);
	if (!(frac -> img))
	{
		mlx_terminate(frac -> mlx);
		error_out("Image buffer allocation failed.");
		exit(EXIT_FAILURE);
	}
	set_viewport(frac);
	set_color(frac);
	mlx_image_to_window(frac -> mlx, frac -> img, 0, 0);
}
