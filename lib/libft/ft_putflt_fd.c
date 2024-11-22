/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflt_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweerasi <wweerasi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:09:30 by wweerasi          #+#    #+#             */
/*   Updated: 2024/11/22 15:16:59 by wweerasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putflt_fd(double dbl, int fd, int prec)
{
	int		nbr;
	double	frc;
	int		i;

	if (dbl < 0)
	{
		write(fd, "-", 1);
		dbl = -dbl;
	}
	nbr = (int)dbl;
	frc = dbl - nbr;
	ft_putnbr_fd(nbr, fd);
	if (prec > 0)
	{
		write(fd, ".", 1);
		i = 0;
		while (i < prec)
		{
			frc *= 10;
			ft_putnbr_fd((int)frc, fd);
			frc -= (int)frc;
			i++;
		}
	}
}
