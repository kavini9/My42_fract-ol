#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	frac;

	if (!is_valid(argc, argv))
		exit(EXIT_FAILURE);
	init_fractol(&frac, argv);
	fractol_render(&frac);
	control_guide();
	mlx_key_hook(frac.mlx, ctrl, &frac);
	mlx_scroll_hook(frac.mlx, zoom, &frac);
	mlx_loop_hook(frac.mlx, shift, &frac);
	mlx_loop(frac.mlx);
	mlx_terminate(frac.mlx);
	return (EXIT_SUCCESS);
	return (0);
}
