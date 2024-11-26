/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:59:53 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/26 12:13:04 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	frac;

	if (is_valid(argc, argv))
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
}
