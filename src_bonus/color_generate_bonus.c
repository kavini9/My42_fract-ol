/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_generate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:54:46 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/22 19:37:29 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

uint32_t	get_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
/*
void	get_color(t_color *pix, int n)
{
	if (n == frac -> max_iter)
	{
		pix -> color = get_pixel(0, 0, 0, 255);
		return ;
	}
	pix -> r = (uint32_t)(sin(n) / 1 * 127.5 + 127.5);
	pix -> g = (uint32_t)(sin(n + M_PI / 3) / 2 * 127.5 + 127.5);
	pix -> b = (uint32_t)(sin(n + 2 * M_PI / 3) / 3 * 127.5 + 127.5);
	pix -> a = 255;
	pix -> color = get_pixel(pix -> r, pix -> g, pix -> b, pix -> a);
}*/
/*
void	get_color(t_color *pix, int n, double mu)
{
	uint8_t r;
 	uint8_t g;
  	uint8_t b;
	uint8_t a;
   
	if (n == frac -> max_iter)
	{
		pix -> color = get_pixel(0, 0, 0, 255);
		return ;
	}
	r = (uint8_t)(pix -> r + (sin(mu) * pix -> radi));
	g = (uint8_t)(pix -> g + (sin(mu + M_PI / 3)/2 * pix -> radi));
	b = (uint8_t)(pix -> b + (sin(mu + 2 * M_PI / 3) / 3* pix -> radi));
	a = 255;
	pix -> color = get_pixel(r, g, b, a);
}*/

void	get_color(t_fractol *frac, int n, double mu)
{
	uint8_t r;
 	uint8_t g;
  	uint8_t b;
	uint8_t a;
	t_color *pix;

	pix = &(frac -> pix);
	if (n == frac -> max_iter)
	{
		pix -> color = get_pixel(0, 0, 0, 255);
		return ;
	}
	r = (uint8_t)(pix -> r * (1 + (sin(mu * M_PI / frac -> max_iter)* pix -> radi)));
	g = (uint8_t)(pix -> g * (1 + (sin((mu / frac -> max_iter + 1/ 3) * M_PI) * pix -> radi)));
	b = (uint8_t)(pix -> b * (1 + (sin((mu / frac -> max_iter + 2/ 3) * M_PI) * pix -> radi)));
	a = 255;
	pix -> color = get_pixel(r, g, b, a);
}

void	set_rgb(double c, double x, t_color *clr)
{
	if ( clr -> h < 60 || clr -> h >= 300)
	{
		clr -> r += c;
		if ( clr -> h < 60)
			clr -> g += x;
		else
			clr -> b += x;
	}
	else if ( clr -> h >= 60 && clr -> h < 180)
	{
		clr -> g += c;
		if ( clr -> h <= 120)
			clr -> r += x;
		else
			clr -> b += x;
	}
	else if ( clr -> h >= 180 && clr -> h < 300)
	{
		clr -> b += c;
		if ( clr -> h <= 240)
			clr -> g += x;
		else
			clr -> r += x;
	}
}

uint32_t	set_palette(t_color *color)
{
	double	c;
	double	x;
	double	m;

	c = color -> v * color -> s;
	x = c * (1 - fabs(fmod(color -> h / 60.0, 2.0) - 1));
	m = color -> v - c;
	color -> r = m;
	color -> g = m;
	color -> b = m;
	set_rgb(c, x, color);
	color -> r *= 255;
	color -> g *= 255;
	color -> b *= 255;
}
	

