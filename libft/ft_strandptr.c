/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strandptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:35:21 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/27 09:35:18 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<unistd.h>
#include	"libft.h"
#include	<stdlib.h>

int	ft_pstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{	
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_printnbr(int n)
{
	char	*nbr;
	int		lenght;

	lenght = 0;
	nbr = ft_itoa(n);
	lenght = ft_pstr(nbr);
	free (nbr);
	return (lenght);
}
