/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 06:46:56 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/11 21:04:56 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	control_guide(void)
{
	ft_putendl_fd(
		"<===========================================================>"
		"\n| \033[4mControl guide\033[0m\t\t\t\t\t\t|"
		"\n| ESC		- Exit program\t\t\t\t|"
		"\n| TAB		- Display control guide\t\t\t\t|"
		"\n| ARROW_KEYS		- Panning\t\t\t\t|"
		"\n| \tUP	- Move up\t\t\t\t|"
		"\n| \tDOWN	- Move down\t\t\t\t|"
		"\n| \tRIGHT	- Move right\t\t\t\t|"
		"\n| \tLEFT	- Move left\t\t\t\t|"
		"\n| MOUSE	- Zooming\t\t\t\t|"
		"\n| \tSCROLL_UP	- Zoom in\t\t\t\t|"
		"\n| \tSCROLL_DOWN	- Zoom out\t\t\t\t|"
		"\n| Color adjustments\t\t\t\t\t\t|"
		"\n| \tH + SHIFT	- Increase Hue\t\t\t\t|"
		"\n| \tH		- Decrease Hue\t\t\t\t|"
		"\n| \tS + SHIFT	- Increase Saturation\t\t\t|"
		"\n| \tS		- Decrease Saturation\t\t\t|"
		"\n| \tV + SHIFT	- Increase Brightness\t\t\t|"
		"\n| \tV		- Decrease Brightness\t\t\t|"
		"\n| Numpad +	- Increase max iterations\t\t\t|"
		"\n| Numpad -	- Decrease max iterations\t\t\t|"
		"\n| R		- Reset color and viewport\t\t\t|"
		"\n<===========================================================>",
		STDERR_FILENO);
}

void	error_out(char *err_msg)
{
	ft_putstr_fd(" fractol: Error: ", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
}

int	arg_guide(char *err_msg)
{
	error_out(err_msg);
	ft_putendl_fd(
		"\n Usage:  ./fractol  <fractal_set>  <Re(c)>  <Im(c)>"
		"\n<===========================================================>"
		"\n| \033[4mfractol argument reference\033[0m\t\t\t\t|"
		"\n| <fractal_set>:\t\t\t\t\t|"
		"\n| \tmandelbrot\t\t\t\t\t|"
		"\n| \tjulia\t\t\t\t\t\t|"
		"\n| \tburning_ship\t\t\t\t\t|"
		"\n| Notes:\t\t\t\t\t\t|"
		"\n| \t- Re(c) and Im(c) are required only for the julia set.|"
		"\n| \tThey are not needed for other fractal sets.\t|"
		"\n| \t- Values for <Re(c)> and <Im(c)> must be within\t|"
		"\n| \tthe range -2 to 2.\t\t\t|"
		"\n| \tExample julia set parameters:\t\t\t|"
		"\n| \t\t<Re(c)>\t<Im(c)>\t\t\t\t|"
		"\n| \t\t-0.4\t0.6\t\t\t\t|"
		"\n| \t\t 0.285\t0.01\t\t\t\t|"
		"\n| \t\t-0.8\t0.156\t\t\t\t|"
		"\n| \t\t-0.7269\t0.1889\t\t\t\t|"
		"\n| \t\t-0.835\t0.2321\t\t\t\t|"
		"\n<===========================================================>",
		STDERR_FILENO);
	return (0);
}
