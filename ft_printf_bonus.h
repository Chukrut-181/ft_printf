/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:41:55 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/05 10:39:27 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define NO 0
# define YES 1 

typedef struct s_format
{
	int		zero_padding;
	int		blank_padding;
	int		pad_field;
	int		align_left;
	int		hashtag;
	int		space_sign;
	int		plus_sign;
	char	d;
}	t_format;

//	FT_PRINTF_BONUS.C
int		ft_printf(char const *str, ...);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);

//	FT_PRINTF_UTILS_BONUS.C
int		ft_printchar(char c);
void	ft_printstr(char *str, int *q);
void	ft_printhex(unsigned long n, int *q, char h);
void	ft_printnbr(int n, int *q);
void	ft_printunsnbr(unsigned int n, int *q);

//	FT_PRINTF_UTILS2_BONUS.C
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

//	FT_PRINTF_FORMAT_BONUS.C
void	ft_check_flags(t_format *format, char f);
void	ft_parse_format(t_format *format, const char *str);
void	ft_determine_padding(t_format *format, const char *pad, int *i);

#endif