/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:21:14 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/23 17:09:11 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	main(int argc, char **argv)
{
	t_fractol	frac;

	if (!is_valid(argc, argv))
		exit(EXIT_FAILURE);
	init_fractol(&frac, argv);
	fractol_render(&frac);
	control_guide();
	mlx_key_hook(frac.mlx, key_ctrls, &frac);
	mlx_scroll_hook(frac.mlx, zoom, &frac);
	mlx_loop_hook(frac.mlx, shift, &frac);
	mlx_loop(frac.mlx);
	mlx_terminate(frac.mlx);
	return (EXIT_SUCCESS);
	return (0);
}
