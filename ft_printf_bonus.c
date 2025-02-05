/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:52:20 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/05 11:29:04 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*mark;

	if (!s)
		return (NULL);
	ch = (char)c;
	mark = NULL;
	while (*s)
	{
		if (*s == ch)
		{
			mark = (char *)s;
			return (mark);
		}
		else
			s++;
	}
	if (ch == '\0')
	{
		mark = (char *)s;
		return (mark);
	}
	return (mark);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (0 < len)
	{
		*p = (unsigned char)c;
		p++;
		len--;
	}
	return (b);
}

static void	ft_checkpointer(size_t adr, int *q, t_format *format)
{
	if (!adr)
		ft_printstr("(nil)", q, format);
	else
	{
		ft_printstr("0x", q, format);
		ft_printhex(adr, q, 'x', format);
	}
}

static void	ft_discriminate(t_format *format, va_list list, int *q)
{
	if (format->specifier == 'c')
		*q += ft_printchar(va_arg(list, int), format);
	else if (format->specifier == 's')
		ft_printstr(va_arg(list, char *), q, format);
	else if (format->specifier == 'p')
		ft_checkpointer(va_arg(list, size_t), q, format);
	else if (format->specifier == 'i' || format->specifier == 'd')
		ft_printnbr(va_arg(list, int), q, format);
	else if (format->specifier == 'u')
		ft_printunsnbr(va_arg(list, unsigned int), q, format);
	else if (format->specifier == 'x')
		ft_printhex(va_arg(list, unsigned int), q, 'x', format);
	else if (format->specifier == 'X')
		ft_printhex(va_arg(list, unsigned int), q, 'X', format);
	else if (format->specifier == '%')
		*q += ft_printchar('%', format);
	else
		return ;
}

int	ft_printf(char const *str, ...)
{
	va_list		list;
	t_format	format;
	int			i;
	int			q;

	va_start(list, str);
	ft_memset(&format, 0, sizeof(t_format));
	i = 0;
	q = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_parse_format(&format, &str[i], &i);
			ft_discriminate(&format, list, &q);
			ft_memset(&format, 0, sizeof(t_format));
		}
		else
			q += ft_printchar(str[i], NULL);
		i++;
	}
	va_end(list);
	return (q);
}
