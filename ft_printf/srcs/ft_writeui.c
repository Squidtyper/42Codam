/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writeui.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 14:07:23 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/16 19:15:49 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"

static unsigned int	ft_wrint(unsigned int n)
{
	char			*str;
	int				len;
	int				lenbuf;
	unsigned int	nbuf;

	len = 1;
	nbuf = n;
	while (nbuf >= 10)
	{
		nbuf = nbuf / 10;
		len++;
	}
	lenbuf = len - 1;
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (0);
	while (lenbuf >= 0)
	{
		str[lenbuf] = n % 10 + 48;
		n = n / 10;
		lenbuf--;
	}
	write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

int	ft_writeui(va_list ap)
{
	int				count;
	unsigned int	uiw;

	uiw = va_arg(ap, unsigned int);
	count = 0;
	if (uiw == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = ft_wrint(uiw);
	return (count);
}
