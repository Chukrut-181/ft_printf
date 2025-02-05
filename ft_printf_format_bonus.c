/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:57:30 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/05 11:18:16 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_determine_padding(t_format *format, const char *pad, int *j)
{
	int		i;
	char	*temp;
	char	*aux;
	char	char_str[2];

	i = 0;
	aux = NULL;
	while ('0' <= pad[i] && pad[i] <= '9')
	{
		char_str[0] = pad[i];
		char_str[1] = '\0';
		temp = ft_strjoin(aux, char_str);
		free(aux);
		aux = temp;
		i++;
		(*j) += 1;
	}
	format->pad_field = ft_atoi(aux);
	free(aux);
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
	if (f == '#')
		format->hashtag = YES;
}

void	ft_parse_format(t_format *format, const char *str, int *k)
{
	int	i;

	i = 0;
	while (!ft_strchr("cspdiuxX%", str[i]))
	{
		while (ft_strchr("-+ #", str[i]))
		{
			ft_check_flags(format, str[i]);
			i++;
		}
		if (str[i] == '0' && format->align_left == NO)
		{
			format->zero_padding = YES;
			i++;
		}
		if ('0' <= str[i] && str[i] <= '9')
			ft_determine_padding(format, &str[i], &i);
	}
	format->specifier = str[i];
	(*k) += i;
}
