/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:33:51 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/27 09:35:09 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<stdarg.h>
#include	<unistd.h>
#include	"libft.h"

int	ft_ppercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_pchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_findform(va_list car, const char form)
{
	int	lenght;

	lenght = 0;
	if (form == 'c')
		lenght += ft_pchar(va_arg(car, int));
	else if (form == 's')
		lenght += ft_pstr(va_arg(car, char *));
	else if (form == 'p')
		lenght += ft_padd(va_arg(car, unsigned long long));
	else if (form == 'd')
		lenght += ft_printnbr(va_arg(car, int));
	else if (form == 'i')
		lenght += ft_printnbr(va_arg(car, int));
	else if (form == 'u')
		lenght += ft_pnbr_unsigned(va_arg(car, unsigned int));
	else if (form == 'x' || form == 'X')
		lenght += ft_hexabase(va_arg(car, unsigned int), form);
	else if (form == '%')
		lenght += ft_ppercent();
	return (lenght);
}

int	ft_printf(const char *str, ...)
{
	va_list		car;
	int			i;
	int			lenght;

	i = 0;
	lenght = 0;
	va_start(car, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			lenght += ft_findform(car, str[i + 1]);
			i++;
		}
		else
			lenght += ft_pchar(str[i]);
		i++;
	}
	va_end(car);
	return (lenght);
}
