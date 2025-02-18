/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:41:10 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/18 16:28:14 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum e_flags
{
	FLAG_MINUS = (1 << 0),
	FLAG_PLUS = (1 << 1),
	FLAG_SPACE = (1 << 2),
	FLAG_HASH = (1 << 3),
	FLAG_ZERO = (1 << 4)
}	t_flags;

typedef struct s_format
{
	int		flags;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

//	FT_PRINTF_BONUS.C
t_format	*ft_init_format(void);
int			ft_printf(char const *str, ...);

//	FT_PRINTF_UTILS.C
int			ft_printchar(char c, t_format *format);

//	FT_PRINTF_UTILS2.C
t_format	*ft_parse_format(const char **str);

//FT_PRINTF_LIBFT_BONUS.C
int			ft_isdigit(int c);
void		*ft_memset(void *b, int c, size_t len);

#endif