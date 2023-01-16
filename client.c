/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:48:05 by hefurrer          #+#    #+#             */
/*   Updated: 2023/01/09 09:48:07 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft/libft.h"
#include	<signal.h>
#include	<stdlib.h>

void	ft_send_it_the_limbo(void)
{
	ft_printf("An error as occured\n");
	exit(0);
}

void	send_str_bit(unsigned char c, int pid)
{
	int	i;

	i = 6;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_send_it_the_limbo();
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_send_it_the_limbo();
		}
		usleep(200);
		i--;
	}
}

void	chopandsend(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		send_str_bit(s[i], pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*strtosend;

	if (ac != 3)
		return (-1);
	pid = ft_atoi(av[1]);
	strtosend = av[2];
	chopandsend(strtosend, pid);
	return (0);
}
