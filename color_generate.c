/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:43:13 by wweerasi          #+#    #+#             */
/*   Updated: 2024/10/29 22:33:18 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_pixel(uint32_t red, uint32_t green, uint32_t blue, uint32_t a)
{
	return (red << 24 | green << 16 | blue << 8 | a);
}

void	get_color(t_color *pix, int n)
{
	if (n == MAX_ITER)
	{
		pix -> color  = get_pixel(0, 0, 0, 255);
		return ;
	}

	double t = n/MAX_ITER;
	uint32_t red_start  = (sin(pix -> red_base * n) * 255);
	uint32_t red_end = (sin(pix -> red_base * (n + 1)) * 255);
	uint32_t green_start = (sin(pix -> green_base * n)/2 * 255);
	uint32_t green_end = (sin(pix -> green_base * (n + 1))/2 * 255);
	uint32_t blue_start = (sin(pix -> blue_base * n)/3 * 255);
	uint32_t blue_end = (sin(pix -> blue_base * (n + 1))/3 * 255);
	pix -> red = (1 - t) * red_start + t/(1 - t) * red_end;
	pix -> green = (1 - t) * green_start + t/(1 - t) * green_end;
	pix -> blue = (1 - t) * blue_start + t/(1 - t) * blue_end;
	//fractol->get.red = t/(1 - t) * red_start + (1 - t) * red_end;
	//fractol->get.green = t/(1 - t) * green_start + (1 - t) * green_end;
	//fractol->get.blue = t/(1 - t) * blue_start + (1 - t) * blue_end;

	pix -> alpha = 255;
	pix -> color = get_pixel(pix -> red, pix -> green, pix -> blue, pix -> alpha);
}
/*
void	get_color(t_color *pix, int n)
{
	if (n == MAX_ITER)
	{
		pix -> color  = get_pixel(0, 0, 0, 255);
		return ;
	}
	pix -> red = (sin(pix -> red_base * n) * 255);
	pix -> green = (sin(pix-> green_base * n) * 255);
	pix -> blue = (sin(pix-> blue_base * n) * 255);
	pix -> alpha = 255;
	pix -> color = get_pixel(pix -> red, pix -> green,
			pix -> blue, pix -> alpha);
}*/
