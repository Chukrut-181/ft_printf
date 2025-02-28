/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:58:46 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/28 15:52:01 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printnbr(int n, int *q, t_format *format)
{
	char	pad_char;
	int		num_len;

	num_len = ft_numlen(n);
	pad_char = ' ';
	if (format && format->flags & FLAG_ZERO)
		pad_char = '0';
	if (!(format->flags & FLAG_MINUS))
		ft_right_align(num_len, format->width, q, pad_char);
	if (n < 0)
		*q += ft_printchar('-', NULL);
	if (n == -2147483648)
		return (ft_printstr("2147483648", q, format));
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_printnbr(n / 10, q, NULL);
	*q += ft_printchar((n % 10) + '0', NULL);
	if (format->flags & FLAG_MINUS)
		ft_left_align(num_len, format->width, q, ' ');
}

int	ft_printchar(char c, t_format *format)
{
	int		q;
	char	pad_char;

	q = 0;
	if (format)
	{
		pad_char = ' ';
		if (format->flags & FLAG_ZERO)
			pad_char = '0';
		if (!(format->flags & FLAG_MINUS))
			ft_right_align(1, format->width, &q, pad_char);
	}
	q += write(1, &c, 1);
	if (format && format->flags & FLAG_MINUS)
		ft_left_align(1, format->width, &q, ' ');
	return (q);
}

void	ft_printstr(char *str, int *q, t_format *format)
{
	int		len;
	char	pad_char;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (format)
	{
		pad_char = ' ';
		if (format->flags & FLAG_ZERO)
			pad_char = '0';
		if (!(format->flags & FLAG_MINUS))
			ft_right_align(len, format->width, q, pad_char);
	}
	while (*str != '\0')
	{
		*q += write(1, str, 1);
		str++;
	}
	if (format && format->flags & FLAG_MINUS)
		ft_left_align(len, format->width, q, ' ');
}
