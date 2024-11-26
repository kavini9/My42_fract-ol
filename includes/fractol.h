/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 07:41:25 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/26 11:39:35 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

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
	double		r;
	double		g;
	double		b;
	uint32_t	color;
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
void	set_color(t_fractol *frac);
void	fractol_render(t_fractol *frac);
void	get_color(t_fractol *frac, int n, double mu);
void	pix_to_cmplex(int x, int y, t_coord *p, t_fractol *frac);
void	zoom(double xdelta, double ydelta, void *param);
void	shift(void *param);
void	ctrl(mlx_key_data_t keydata, void *param);
void	error_out(char *error_msg);

#endif
