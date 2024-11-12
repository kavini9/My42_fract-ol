/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 07:41:25 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/11 22:50:53 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <unistd.h>//see if this needed here
# include <stdlib.h>//see if this is needed here 
# include <math.h>

# define WIDTH 1500
# define HEIGHT 1500

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_color
{
	double		h;
	double		s;
	double		v;
	double		r;
	double		g;
	double		b;
	uint32_t	a;
	uint32_t	color;
	uint8_t		radi;
}	t_color;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*f_set;
	t_coord		max;
	t_coord		min;
	t_coord		z;
	t_coord		c;
	t_color		pix;
	int		max_iter;
	int			n;
	double		mu;

}	t_fractol;

int		arg_guide(char *err_msg);
int		control_guide(void);
int		is_valid(int ac, char **av);
void	init_fractol(t_fractol *frac, char **av);
void	set_color(t_fractol *frac);
void	fractol_render(t_fractol *frac);
void	get_color(t_color *pix, int n, double mu);
uint32_t	set_palette(t_color *color);
void	pix_to_cmplex(int x, int y, t_coord *p, t_fractol *frac);
void	zoom(double xdelta, double ydelta, void *param);
void	shift(void *param);
void	esc(mlx_key_data_t keydata, void *param);
void	error_out(char *error_msg);

#endif
