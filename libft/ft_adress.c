/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 08:55:16 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/27 09:34:15 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

int	ft_addlenght(uintptr_t add)
{
	int	lenght;

	lenght = 0;
	while (add != 0)
	{
		lenght++;
		add /= 16;
	}
	return (lenght);
}

void	ft_convadd(uintptr_t add)
{
	if (add >= 16)
	{
		ft_convadd(add / 16);
		ft_convadd(add % 16);
	}
	else
	{
		if (add <= 9)
			ft_putchar_fd((add + '0'), 1);
		else
			ft_putchar_fd((add - 10 + 'a'), 1);
	}
}

int	ft_padd(unsigned long long add)
{
	int	lenght;

	lenght = 0;
	lenght += write(1, "0x", 2);
	if (add == 0)
		lenght += write(1, "0", 1);
	else
	{
		ft_convadd(add);
		lenght += ft_addlenght(add);
	}
	return (lenght);
}
