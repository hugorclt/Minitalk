/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:05:00 by hrecolet          #+#    #+#             */
/*   Updated: 2021/11/30 18:25:18 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * (-1);
		write(1, "-", 1);
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * (-1);
		write(1, "-", 1);
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putnbr_base(unsigned int n)
{
	char			*base;
	unsigned int	nb;

	base = "0123456789abcdef";
	nb = n;
	if (nb >= 16)
	{
		ft_putnbr_base(nb / 16);
		ft_putnbr_base(nb % 16);
	}
	else
		ft_putchar(base[nb % 16]);
}

void	ft_putnbr_base_maj(unsigned int n)
{
	char			*base;
	unsigned int	nb;

	base = "0123456789ABCDEF";
	nb = n;
	if (nb >= 16)
	{
		ft_putnbr_base_maj(nb / 16);
		ft_putnbr_base_maj(nb % 16);
	}
	else
		ft_putchar(base[nb % 16]);
}

void	ft_putnbr_base_unsigned(unsigned long n)
{
	char			*base;
	unsigned long	nb;

	base = "0123456789abcdef";
	nb = n;
	if (nb >= 16)
	{
		ft_putnbr_base_unsigned(nb / 16);
		ft_putnbr_base_unsigned(nb % 16);
	}
	else
		ft_putchar(base[nb % 16]);
}
