/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:35:39 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/27 09:35:30 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"
#include	<stdlib.h>

int	ft_nbrlenght(unsigned int nbr)
{
	int	lenght;

	lenght = 0;
	while (nbr != 0)
	{
		lenght++;
		nbr /= 10;
	}
	return (lenght);
}

char	*ft_unsigneditoa(unsigned int nbr)
{
	char	*number;
	int		size;

	size = ft_nbrlenght(nbr);
	number = malloc(sizeof(char) + (size + 1));
	if (!number)
		return (NULL);
	number[size] = '\0';
	while (nbr != 0)
	{
		number[size - 1] = (nbr % 10) + '0';
		nbr /= 10;
		size--;
	}
	return (number);
}

int	ft_pnbr_unsigned(unsigned int nbr)
{
	int		lenght;
	char	*number;

	lenght = 0;
	if (nbr == 0)
		lenght += write(1, "0", 1);
	else
	{
		number = ft_unsigneditoa(nbr);
		lenght += ft_pstr(number);
		free (number);
	}
	return (lenght);
}
