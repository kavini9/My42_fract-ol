#include "fractol.h"

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

static void	set_julia_c(t_fractol *frac, char **av)
{
	frac -> c.x = ft_atof(av[2]);
	frac -> c.y = ft_atof(av[3]);
	if ((frac -> c.x > 2.0 || frac -> c.x < -2.0)
		|| (frac -> c.y > 2.0 || frac -> c.y < -2.0))
	{
		arg_guide("Argument values are out of range.");
		mlx_terminate(frac -> mlx);
		exit(EXIT_FAILURE);
	}
}

void	init_fractol(t_fractol *frac, char **av)
{
	frac -> f_set = av[1];
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
	if (!(ft_strcmp(frac -> f_set, "julia")))
		set_julia_c(frac, av);
	set_viewport(frac);
	mlx_image_to_window(frac -> mlx, frac -> img, 0, 0);
}
