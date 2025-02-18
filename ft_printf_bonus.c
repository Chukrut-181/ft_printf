/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:45:54 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/18 16:52:04 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_discriminate(t_format *format, va_list list, int *q)
{
	if (format->specifier == 'c')
		*q += ft_printchar(va_arg(list, int), format);
	else if (format->specifier == 's')
		ft_printstr(va_arg(list, char *), q, format);
/*	else if (format->specifier == 'p')
		ft_checkpointer(va_arg(list, size_t), q);
	else if (format->specifier == 'i' || format->specifier == 'd')
		ft_printnbr(va_arg(list, int), q);
	else if (format->specifier == 'u')
		ft_printunsnbr(va_arg(list, unsigned int), q);
	else if (format->specifier == 'x')
		ft_printhex(va_arg(list, unsigned int), q, 'x');
	else if (format->specifier == 'X')
		ft_printhex(va_arg(list, unsigned int), q, 'X'); */
	else if (format->specifier == '%')
		*q += ft_printchar('%', format);
	else
		return ;
}

t_format	*ft_init_format(void)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	format->flags = 0;
	format->width = 0;
	format->precision = 0;
	format->specifier = '\0';
	return (format);
}

int	ft_printf(char const *str, ...)
{
	va_list		list;
	t_format	*format;
	int			i;
	int			q;

	va_start(list, str);
	i = 0;
	q = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			format = ft_parse_format(&str);
			ft_discriminate(format, list, &q);
			free(format);
		}
		else
			q += ft_printchar(*str, NULL);
		str++;
	}
	va_end(list);
	return (q);
}
