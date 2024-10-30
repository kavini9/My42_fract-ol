/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exeption_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:52:35 by wweerasi          #+#    #+#             */
/*   Updated: 2024/10/27 18:50:21 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

int arg_guide(char *err_msg)
{
	ft_putstr_fd(" fractol: Error: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	ft_putendl_fd(
	"\n Usage:  ./fractol  <fractal_set>  <Re(c)>  <Im(c)>"
	"\n<===============================================================>"
	"\n| \033[4mfractol argument reference\033[0m\t\t\t\t\t|"
	"\n| <fractal_set>:\t\t\t\t\t\t|"
	"\n| \tmandelbrot\t\t\t\t\t\t|"
	"\n| \tjulia\t\t\t\t\t\t\t|"
	"\n| \tsomething\t\t\t\t\t\t|"
	"\n| Notes:\t\t\t\t\t\t\t|"
	"\n| \t- Re(c) and Im(c) are required only for the julia set.\t|"
	"\n| \tThey are not needed for other fractal sets.\t\t|"
	"\n| \t- Values for <Re(c)> and <Im(c)> must be within\t\t|"
	"\n| \tthe range -2 to 2.\t\t\t\t\t|"
	"\n| \tExample julia set parameters:\t\t\t\t|"
	"\n| \t\t<Re(c)>\t<Im(c)>\t\t\t\t\t|"
	"\n| \t\t-0.4\t0.6\t\t\t\t\t|"
	"\n| \t\t 0.285\t0.01\t\t\t\t\t|"
	"\n| \t\t-0.8\t0.156\t\t\t\t\t|"
	"\n| \t\t-0.7269\t0.1889\t\t\t\t\t|"
	"\n| \t\t-0.835\t0.2321\t\t\t\t\t|"
	"\n<===============================================================>",
	STDERR_FILENO);
	return(0);
}
