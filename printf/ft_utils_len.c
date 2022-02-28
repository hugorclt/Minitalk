/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:52:50 by hrecolet          #+#    #+#             */
/*   Updated: 2021/11/30 18:27:21 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_number_length_pointer(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_number_length(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_number_length_hex(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_unsigned(va_list args)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(args, unsigned int);
	ft_putnbr_unsigned(nb);
	len = ft_number_length(nb);
	return (len);
}

int	ft_hex(va_list args)
{
	int	nb;
	int	len;

	nb = va_arg(args, int);
	ft_putnbr_base(nb);
	len = ft_number_length_hex(nb);
	return (len);
}
