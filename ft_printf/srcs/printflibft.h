/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printflibft.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 01:56:46 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/02 22:32:11 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef	 PRINTFLIBFT_H
# define PRINTFLIBFT_H
# include "../libft/libft.h"
# include <stdarg.h>

int	ft_writehex(size_t i, int caseind);
int	ft_writestd(const char *str);
int	ft_writeint(va_list ap);
int	ft_writeui(va_list ap);
int	ft_writechar(va_list ap);
int	ft_writestr(va_list ap);
int	ft_writevoid(va_list ap);
int	ft_writex(va_list ap, int caseind);
int	ft_writenull(char *str);

int	ft_printf(const char *tinput, ...);

#endif
