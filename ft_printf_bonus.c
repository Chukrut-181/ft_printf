/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:52:20 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/05 10:23:27 by igchurru         ###   ########.fr       */
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

static void	ft_checkpointer(size_t adr, int *q)
{
	if (!adr)
		ft_printstr("(nil)", q);
	else
	{
		ft_printstr("0x", q);
		ft_printhex(adr, q, 'x');
	}
}

static void	ft_discriminate(char d, va_list list, int *q)
{
	if (d == 'c')
		*q += ft_printchar(va_arg(list, int));
	else if (d == 's')
		ft_printstr(va_arg(list, char *), q);
	else if (d == 'p')
		ft_checkpointer(va_arg(list, size_t), q);
	else if (d == 'i' || d == 'd')
		ft_printnbr(va_arg(list, int), q);
	else if (d == 'u')
		ft_printunsnbr(va_arg(list, unsigned int), q);
	else if (d == 'x')
		ft_printhex(va_arg(list, unsigned int), q, 'x');
	else if (d == 'X')
		ft_printhex(va_arg(list, unsigned int), q, 'X');
	else if (d == '%')
		*q += ft_printchar('%');
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
			ft_parse_format(&format, &str[i]);
			ft_discriminate(str[i], list, &q);
		}
		else
			q += ft_printchar(str[i]);
		i++;
	}
	va_end(list);
	return (q);
}
