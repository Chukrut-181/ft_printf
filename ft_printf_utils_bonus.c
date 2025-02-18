/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:58:46 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/18 16:47:51 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_printstr(char *str, int *q, t_format *format)
{
	int	i;
	int	len;
	int	pad_len;

	if (!str)
		return (ft_printstr("(null)", q, NULL));
	i = 0;
	len = ft_strlen(str);
	pad_len = format->width - len;
	while (pad_len > 0 && !(format->flags & FLAG_MINUS))
	{
		*q += ft_printchar(' ', NULL);
		pad_len--;
	}
	while (str[i])
	{
		*q += ft_printchar(str[i], NULL);
		i++;
	}
	while (pad_len > 0 && format->flags & FLAG_MINUS)
	{
		*q += ft_printchar(' ', NULL);
		pad_len--;
	}
}

int	ft_printchar(char c, t_format *format)
{
	int	count;
	int	padding;

	if (!format)
		return (write(1, &c, 1));
	count = 0;
	padding = format->width - 1;
	while (padding > 0 && !(format->flags & FLAG_MINUS))
	{
		count += write(1, " ", 1);
		padding--;
	}
	count += write(1, &c, 1);
	while (padding > 0 && format->flags & FLAG_MINUS)
	{
		count += write(1, " ", 1);
		padding--;
	}
	return (count);
}
