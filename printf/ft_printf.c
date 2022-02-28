/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:48:16 by hrecolet          #+#    #+#             */
/*   Updated: 2021/11/30 19:04:57 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_maj(va_list args)
{
	int	nb;
	int	len;

	nb = va_arg(args, int);
	ft_putnbr_base_maj(nb);
	len = ft_number_length_hex(nb);
	return (len);
}

int	ft_perc(void)
{
	ft_putchar('%');
	return (1);
}

int	ft_error(char c)
{
	ft_putchar(c);
	return (1);
}

int	ft_parse(va_list args_list, int index, const char *str)
{
	int	ret;

	ret = 0;
	index++;
	if (str[index] == 'c')
		ret += ft_char(args_list);
	else if (str[index] == 's')
		ret += ft_str(args_list);
	else if (str[index] == 'p')
		ret += ft_pointer(args_list);
	else if (str[index] == 'd')
		ret += ft_dec(args_list);
	else if (str[index] == 'i')
		ret += ft_int(args_list);
	else if (str[index] == 'u')
		ret += ft_unsigned(args_list);
	else if (str[index] == 'x')
		ret += ft_hex(args_list);
	else if (str[index] == 'X')
		ret += ft_hex_maj(args_list);
	else if (str[index] == '%')
		ret += ft_perc();
	else
		ret += ft_error(str[index]);
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args_list;
	int		i;
	int		ret;

	va_start(args_list, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += ft_parse(args_list, i, str);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			ret++;
		}
		i++;
	}
	return (ret);
}
