/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:26:11 by hrecolet          #+#    #+#             */
/*   Updated: 2021/11/30 18:27:28 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

int	ft_str(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
}

int	ft_pointer(va_list args)
{
	unsigned long	nb;
	int				len;

	len = 0;
	nb = va_arg(args, unsigned long);
	ft_putstr("0x");
	ft_putnbr_base_unsigned(nb);
	len = ft_number_length_pointer(nb);
	return (len + 2);
}

int	ft_dec(va_list args)
{
	int	nb;
	int	len;

	nb = va_arg(args, int);
	ft_putnbr(nb);
	len = ft_number_length(nb);
	if (nb < 0)
		len++;
	return (len);
}

int	ft_int(va_list args)
{
	int	nb;
	int	len;

	nb = va_arg(args, int);
	ft_putnbr(nb);
	len = ft_number_length(nb);
	if (nb < 0)
		len++;
	return (len);
}
