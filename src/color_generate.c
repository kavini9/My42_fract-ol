/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_generate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:54:46 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/26 12:10:46 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static uint32_t	get_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	get_color(t_fractol *frac, int n, double mu)
{
	t_color	*pix;

	pix = &(frac -> pix);
	if (n == frac -> max_iter)
	{
		pix -> color = get_pixel(0, 0, 0, 255);
		return ;
	}
	pix -> r = (uint32_t)(sin(mu) / 1 * 127.5 + 127.5);
	pix -> g = (uint32_t)(sin(mu + M_PI / 3) / 2 * 127.5 + 127.5);
	pix -> b = (uint32_t)(sin(mu + 2 * M_PI / 3) / 3 * 127.5 + 127.5);
	pix -> color = get_pixel(pix -> r, pix -> g, pix -> b, 255);
}
