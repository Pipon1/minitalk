/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:13:05 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/13 11:23:28 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<stdlib.h>
#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		size;
	char	*res;
	int		i;

	i = 0;
	size = ft_strlen(s);
	res = malloc(sizeof(char) + size);
	if (!res)
		return (NULL);
	while (i < size)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
