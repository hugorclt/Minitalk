/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:48:33 by hrecolet          #+#    #+#             */
/*   Updated: 2021/11/30 18:29:20 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putnbr_unsigned(unsigned int n);
void	ft_putnbr_base_unsigned(unsigned long n);
void	ft_putnbr_base_maj(unsigned int n);
void	ft_putnbr_base(unsigned int n);
int		ft_strlen(char *str);
int		ft_number_length(long nb);
int		ft_number_length_hex(unsigned int nb);
int		ft_number_length_pointer(unsigned long nb);
int		ft_hex(va_list args);
int		ft_unsigned(va_list args);
int		ft_char(va_list args);
int		ft_str(va_list args);
int		ft_pointer(va_list args);
int		ft_dec(va_list args);
int		ft_int(va_list args);

#endif
