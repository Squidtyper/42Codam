/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/24 12:03:11 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/02 23:16:52 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"
#include <stdio.h>

static int	ft_arginset(char c)
{
	char	set[10];
	int		count;

	count = 0;
	ft_memcpy(set, "cspdiuxX%", 10);
	while (c != set[count] && set[count] != 0)
		count++;
	if (count > 8)
		return (0);
	return (count + 1);
}

static int	ft_writearg(va_list ap, char indicator)
{
	if (ft_arginset(indicator) > 0)
	{
		if (indicator == '%')
		{
			write(1, "%", 1);
			return (1);
		}
		else if (indicator == 'c')
			return (ft_writechar(ap));
		else if (indicator == 's')
			return (ft_writestr(ap));
		else if (indicator == 'p')
			return (ft_writevoid(ap));
		else if (indicator == 'd' || indicator == 'i')
			return (ft_writeint(ap));
		else if (indicator == 'u')
			return (ft_writeui(ap));
		else if (indicator == 'x')
			return (ft_writex(ap, 0));
		else if (indicator == 'X')
			return (ft_writex(ap, 1));
	}
	return (0);
}

int	ft_printf(const char *tinput, ...)
{
	va_list	ap;
	char	*tinputbuf;
	int		len;
	int		printlen;

	tinputbuf = (char *)tinput;
	va_start(ap, tinput);
	len = 0;
	printlen = 0;
	while (tinputbuf[0])
	{
		len = ft_writestd(tinputbuf);
		tinputbuf = tinputbuf + len;
		if (tinputbuf[0] == '%')
		{
			printlen = printlen + ft_writearg(ap, tinputbuf[1]);
			if (ft_arginset(tinputbuf[1]) > 0)
				tinputbuf++;
			tinputbuf++;
		}
		printlen = printlen + len;
	}
	va_end(ap);
	return (printlen);
}
