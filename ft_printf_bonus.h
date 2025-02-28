/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:41:10 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/28 15:49:10 by igchurru         ###   ########.fr       */
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

//	FT_PRINTF BONUS
t_format	*ft_init_format(void);
int			ft_printf(char const *str, ...);

//	FT_PRINTF UTILS
void		ft_printstr(char *str, int *q, t_format *format);
int			ft_printchar(char c, t_format *format);

//	FT_PRINTF PARSE UTILS
t_format	*ft_parse_format(const char **str);

//	FT_PRINTF PADDING
int			ft_numlen(int n);
void		ft_apply_padding(int pad_len, char pad_char, int *q);
void		ft_left_align(int content_len, int width, int *q, char pad_char);
void		ft_right_align(int content_len, int width, int *q, char pad_char);

//FT_PRINTF LIBFT BONUS.C 
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
void		*ft_memset(void *b, int c, size_t len);

#endif