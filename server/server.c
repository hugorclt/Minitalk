/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:03:29 by hrecolet          #+#    #+#             */
/*   Updated: 2022/01/11 14:28:42 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len > 0)
	{
		*ptr++ = (unsigned char)c;
		len--;
	}
	return (b);
}

void	handle_message(int sig)
{
	static int	bits = 7;
	static char	buffer[BUFF_SIZE];
	static int	i;

	if (sig == SIGUSR1)
		buffer[i] |= (1 << bits);
	else if (sig == SIGUSR2)
		buffer[i] &= ~(1 << bits);
	bits--;
	if (bits == -1)
	{
		bits = 7;
		if (buffer[i] == '\0')
		{
			write(1, &buffer, i);
			ft_memset(buffer, 0, BUFF_SIZE);
		}
		else
			i++;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handle_message);
		signal(SIGUSR2, handle_message);
	}
}
