/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:57:30 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/04 17:31:44 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

void	ft_check_flags(t_format *format, char f)
{
	if (f == '-')
		format->align_left = YES;
	if (f == '+')
	{
		format->plus_sign = YES;
		format->space_sign = NO;
	}
	else if (f == ' ' && format->plus_sign == NO)
		format->space_sign = YES;
}

void	ft_parse_format(t_format *format, char *str)
{
	int	i;

	i = 0;
	while (!ft_strchr("cspdiuxX%", str[i]))
	{
		while (str[i] == '-' || str[i] == '+' || str[i] == ' ')
		{
			ft_check_flags(format, str[i]);
			i++;
		}
		if (str[i] == '0' && format->align_left == NO)
			format->zero_padding = YES;
		i++;
	}
}
