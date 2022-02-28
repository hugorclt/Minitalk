/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:19:06 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/11 12:23:44 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	result;
	int			signe;

	i = 0;
	result = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * signe > 2147483647)
			return (-1);
		if (result * signe < -2147483648)
			return (0);
		i++;
	}
	return (result * signe);
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit != -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit--;
	}
}

void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char **av)
{
	if (ac == 3)
		send_str(ft_atoi(av[1]), av[2]);
	else
	{
		ft_printf("Invalid Parameters");
		return (0);
	}
}
