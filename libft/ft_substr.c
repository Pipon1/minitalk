/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:30:48 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/13 14:14:00 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"
#include	<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	char	*res;

	slen = ft_strlen(s);
	if (start >= slen || !len)
		return (ft_strdup(""));
	else
		slen -= start;
	if (slen > len)
		slen = len;
	res = malloc(slen + 1 * sizeof(char));
	if (!res)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i])
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}
