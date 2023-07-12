/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writeint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 14:07:23 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/16 19:09:57 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"

static int	ft_wrint(int n)
{
	char	*str;
	int		len;
	int		lenbuf;
	int		nbuf;

	len = 1;
	nbuf = n;
	while (nbuf <= -10 || nbuf >= 10)
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

int	ft_writeint(va_list ap)
{
	int		count;
	int		iw;

	iw = va_arg(ap, int);
	count = 0;
	if (iw == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (iw == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (iw < 0)
	{
		write(1, "-", 1);
		iw = -iw;
		count++;
	}
	count = count + ft_wrint(iw);
	return (count);
}
