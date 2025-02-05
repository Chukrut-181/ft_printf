/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:36:51 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/05 11:18:58 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = (sign * -1);
			str++;
		}
		else
			str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		lens1;
	int		lens2;

	if (s1 || s2)
	{
		lens1 = ft_strlen(s1);
		lens2 = ft_strlen(s2);
		s3 = (char *)malloc(1 * (lens1 + lens2 + 1));
		if (s3 == NULL)
			return (NULL);
		i = -1;
		while (s1 && s1[++i])
			s3[i] = s1[i];
		i = -1;
		while (s2 && s2[++i])
		{
			s3[lens1] = s2[i];
			lens1++;
		}
		s3[lens1] = '\0';
		return (s3);
	}
	return (NULL);
}
