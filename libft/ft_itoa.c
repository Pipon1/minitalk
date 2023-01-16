/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:35:41 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/13 11:10:10 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<stdlib.h>

char	*ft_maken(char *s, long int n, int neg, int size)
{
	if (neg)
		s[0] = '-';
	s[size-- + neg] = '\0';
	while (size)
	{
		s[size + neg] = (n % 10) + '0';
		n /= 10;
		size--;
	}
	s[neg] = n + '0';
	return (s);
}

static size_t	ft_nbsize(long int n)
{
	size_t	size;

	size = 1;
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long int	size;
	long int	nb;
	char		*res;
	int			neg;

	neg = 0;
	nb = n;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	size = ft_nbsize(nb);
	res = malloc(size * sizeof(char) + 1 + neg);
	if (!res)
		return (NULL);
	return (ft_maken(res, nb, neg, size));
}
