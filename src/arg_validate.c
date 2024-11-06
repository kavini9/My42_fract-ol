/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:07:12 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/03 07:30:46 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_float(char *str)
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
	if (!ft_strcmp(av[1], "mandelbrot"))
	{
		if (ac != 2)
			return (arg_guide("Invalid number of arguments"));
		else
			return (1);
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
				return (1);
		}
	}
	else
		return (arg_guide("Invalid argument: <fractal_set>"));
}
