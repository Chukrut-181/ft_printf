/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:56:08 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/05 11:18:41 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printchar(char c, t_format *format)
{
	int	k;

	k = 0;
	while (format && format->pad_field > 1)
	{
		write(1, " ", 1);
		format->pad_field--;
		k++;
	}
	return (k + (write (1, &c, 1)));
}

void	ft_printstr(char *str, int *q)
{
	int	i;

	if (!str)
		return (ft_printstr("(null)", q));
	i = 0;
	while (str[i])
	{
		*q += ft_printchar(str[i], NULL);
		i++;
	}
}

void	ft_printhex(unsigned long n, int *q, char h)
{
	if (15 < n)
		ft_printhex(n / 16, q, h);
	if (h == 'x' || h == 'p')
		*q += ft_printchar("0123456789abcdef"[n % 16], NULL);
	else if (h == 'X')
		*q += ft_printchar("0123456789ABCDEF"[n % 16], NULL);
}

void	ft_printnbr(int n, int *q)
{
	if (n == -2147483648)
	{
		ft_printstr("-2147483648", q);
		return ;
	}
	if (n < 0)
	{
		*q += ft_printchar('-', NULL);
		n = -n;
	}
	if (9 < n)
		ft_printnbr(n / 10, q);
	*q += ft_printchar((n % 10 + '0'), NULL);
}

void	ft_printunsnbr(unsigned int n, int *q)
{
	if (9 < n)
		ft_printunsnbr(n / 10, q);
	*q += ft_printchar((n % 10 + '0'), NULL);
}
