/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:28:13 by hefurrer          #+#    #+#             */
/*   Updated: 2023/01/09 09:28:21 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft/libft.h"
#include	<unistd.h>
#include	<signal.h>

void	sig_handler(int sig)
{
	static int	char_val;
	static int	actbit;

	if (!char_val)
		char_val = 0;
	if (!actbit)
		actbit = 0;
	if (sig == SIGUSR2)
		char_val = (char_val << 1) + 1;
	if (sig == SIGUSR1)
		char_val = char_val << 1;
	if (actbit == 6)
	{
		ft_putchar_fd(char_val, 1);
		actbit = 0;
		char_val = 0;
		return ;
	}
	actbit++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid : %d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
