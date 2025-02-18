/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:54:03 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/18 16:34:07 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_pf_atoi(char k)
{
	int	result;

	result = k - '0';
	return (result);
}

static void	ft_parse_width(t_format *format, const char **str)
{
	int	i;

	i = 0;
	while (ft_isdigit(**str))
	{
		format->width *= 10;
		format->width += ft_pf_atoi(**str);
		(*str)++;
	}
}

static int	ft_is_flag(char c)
{
	return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
}

static void	ft_parse_flags(t_format *format, const char **str)
{
	int	flags;

	flags = 0;
	while (ft_is_flag(**str))
	{
		if (**str == '-')
			format->flags |= FLAG_MINUS;
		else if (**str == '+')
			format->flags |= FLAG_PLUS;
		else if (**str == ' ')
			format->flags |= FLAG_SPACE;
		else if (**str == '#')
			format->flags |= FLAG_HASH;
		else if (**str == '0')
			format->flags |= FLAG_ZERO;
		(*str)++;
	}
}

t_format	*ft_parse_format(const char **str)
{
	t_format	*format;

	format = ft_init_format();
	ft_parse_flags(format, str);
	ft_parse_width(format, str);
	format->specifier = **str;
	return (format);
}
