/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_generate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:54:46 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/03 06:08:44 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	get_color(t_color *pix, int n)
{
	if (n == MAX_ITER)
	{
		pix -> color = get_pixel(0, 0, 0, 255);
		return;
	}

	pix -> r  = (uint32_t)(sin(n)/ 1 * 127.5 + 127.5);
	pix -> g = (uint32_t)(sin(n + M_PI /3) / 2 * 127.5 + 127.5);
	pix -> b = (uint32_t)(sin(n + 2 * M_PI / 3)/ 3 * 127.5 + 127.5);
	pix -> a = 255;
	pix -> color = get_pixel(pix -> r, pix -> g, pix -> b, pix -> a);
}
