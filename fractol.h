/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:36:59 by wweerasi          #+#    #+#             */
/*   Updated: 2024/10/30 21:48:58 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include <unistd.h>//see if this needed here
# include <stdlib.h>//see if this is needed here 
# include <math.h>

# define WIDTH 1500
# define HEIGHT 1500
# define MAX_ITER 500

typedef struct s_coord
{
	double	x;
	double	y;
} t_coord;

typedef struct s_color
{
	double	red_base;
	double	green_base;
	double	blue_base;
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
	uint32_t	alpha;
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
	int		n;

} t_fractol;

int arg_guide(char *err_msg);
int control_guide(void);
int	is_valid(int ac, char **av);
void init_fractol(t_fractol *frac, char **av);
void	fractol_render(t_fractol *frac);
void get_color(t_color *pix, int n);
void	pix_to_cmplex(int x, int y, t_coord *p, t_coord min, t_coord max);
void zoom(double xdelta, double ydelta, void* param);
void shift(void* param);
void	esc(mlx_key_data_t keydata, void *param);




#endif
