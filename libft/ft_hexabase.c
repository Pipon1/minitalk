/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:10:01 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/27 09:34:25 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

int	ft_hexsize(unsigned int nbr)
{
	int	lenght;

	lenght = 0;
	while (nbr != 0)
	{
		lenght++;
		nbr /= 16;
	}
	return (lenght);
}

void	ft_printhex(unsigned int nbr, const char form)
{
	if (nbr >= 16)
	{
		ft_printhex(nbr / 16, form);
		ft_printhex(nbr % 16, form);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar_fd((nbr + '0'), 1);
		else
		{
			if (form == 'x')
				ft_putchar_fd((nbr - 10 + 'a'), 1);
			else if (form == 'X')
				ft_putchar_fd((nbr - 10 + 'A'), 1);
		}
	}
}

int	ft_hexabase(unsigned int nbr, const char form)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_printhex(nbr, form);
	return (ft_hexsize(nbr));
}	
