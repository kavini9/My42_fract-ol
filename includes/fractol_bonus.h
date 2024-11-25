/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:13:07 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/25 17:47:12 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
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
	int			max_iter;
	int			n;
	double		mu;

}	t_fractol;

int		arg_guide(char *err_msg);
int		is_valid(int ac, char **av);
void	control_guide(void);
void	init_fractol(t_fractol *frac, char **av);
void	set_viewport(t_fractol *frac);
void	set_color(t_fractol *frac);
void	fractol_render(t_fractol *frac);
void	get_color(t_fractol *frac, int n, double mu);
void	set_palette(t_color *color);
void	pix_to_cmplex(int x, int y, t_coord *p, t_fractol *frac);
void	zoom(double xdelta, double ydelta, void *param);
void	shift(void *param);
void	key_ctrls(mlx_key_data_t keydata, void *param);
void	prog_ctrls(mlx_key_data_t keydata, t_fractol *frac);
void	color_ctrls(mlx_key_data_t keydata, t_fractol *frac);
void	error_out(char *error_msg);

#endif
