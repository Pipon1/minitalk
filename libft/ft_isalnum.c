/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:58:54 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/11 11:21:37 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c))
		return (1);
	else if (ft_isalpha(c))
		return (1);
	return (0);
}
