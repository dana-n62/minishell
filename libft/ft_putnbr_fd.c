/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: DaNa <dna2@student.42amman.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 10:57:21 by DaNa              #+#    #+#             */
/*   Updated: 2025/08/12 14:08:41 by DaNa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		value;
	char	temp;

	value = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		value = n * (-1);
	}
	else
	{
		value = n;
	}
	if (value / 10 != 0)
	{
		ft_putnbr_fd(value / 10, fd);
	}
	temp = value % 10 + 48;
	write(fd, &temp, sizeof(temp));
}
