/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_generate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:54:46 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/26 18:04:07 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static uint32_t	get_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	get_color(t_fractol *frac, int n, double mu)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	double	sin_f;

	if (n == frac -> max_iter)
	{
		frac -> pix.color = get_pixel(0, 0, 0, 255);
		return ;
	}
	sin_f = sin(2 * mu * M_PI / frac -> max_iter);
	if (sin_f >= 0)
	{
		r = (1 - sin_f) * frac -> pix.r + 255 * sin_f;
		g = (1 - sin_f) * frac -> pix.g + 255 * sin_f;
		b = (1 - sin_f) * frac -> pix.b + 255 * sin_f;
	}
	else
	{
		r = (1 + sin_f) * frac -> pix.r - 50 * sin_f;
		g = (1 + sin_f) * frac -> pix.g - 50 * sin_f;
		b = (1 + sin_f) * frac -> pix.b - 50 * sin_f;
	}
	frac -> pix.color = get_pixel(r, g, b, 255);
}

static void	set_rgb(double c, double x, t_color *clr)
{
	if (clr -> h < 60 || clr -> h >= 300)
	{
		clr -> r += c;
		if (clr -> h < 60)
			clr -> g += x;
		else
			clr -> b += x;
	}
	else if (clr -> h >= 60 && clr -> h < 180)
	{
		clr -> g += c;
		if (clr -> h <= 120)
			clr -> r += x;
		else
			clr -> b += x;
	}
	else if (clr -> h >= 180 && clr -> h < 300)
	{
		clr -> b += c;
		if (clr -> h <= 240)
			clr -> g += x;
		else
			clr -> r += x;
	}
}

void	set_palette(t_color *color)
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
