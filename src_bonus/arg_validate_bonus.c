/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:54:21 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/26 19:19:05 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static int	is_float(char *str)
{
	int	dec_flag;
	int	digit_count;

	dec_flag = 0;
	digit_count = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit((unsigned char) *str) && *str != '.')
			return (0);
		else if (*str == '.')
		{
			if (dec_flag || !digit_count)
				return (0);
			dec_flag = digit_count;
		}
		else
			digit_count++;
		str++;
	}
	return (digit_count - dec_flag);
}

int	is_valid(int ac, char **av)
{
	if (ac < 2 || ac == 3 || ac > 4)
		return (arg_guide("Invalid number of arguments"));
	if (!ft_strcmp(av[1], "mandelbrot")
		|| !ft_strcmp(av[1], "burning_ship"))
	{
		if (ac != 2)
			return (arg_guide("Invalid number of arguments"));
		else
			return (0);
	}
	else if (!ft_strcmp(av[1], "julia"))
	{
		if (ac != 4)
			return (arg_guide("Invalid number of arguments"));
		else
		{
			if (!is_float(av[2]) || !is_float(av[3]))
				return (arg_guide("Invalid argument type."));
			else
				return (0);
		}
	}
	else
		return (arg_guide("Invalid argument: <fractal_set>"));
}
