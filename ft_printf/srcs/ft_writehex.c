/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writehex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 16:24:43 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/02 22:31:33 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"
#include <stdio.h>

static char	*ft_dtohexstr(size_t i)
{
	int		len;
	size_t	buf;
	char	*str;
	int		count;

	len = 0;
	buf = i;
	count = 0;
	while (buf > 0)
	{
		buf = buf / 16;
		len++;
	}
	str = ft_calloc(len + 1, 1);
	if (str == NULL)
		return (NULL);
	while (i > 0)
	{
		len--;
		str[len] = i % 16 + '0';
		if (str[len] > '9')
			str[len] = str[len] + 7;
		i = i / 16;
	}
	return (str);
}

int	ft_writehex(size_t i, int caseind)
{
	char	*str;
	int		count;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	str = ft_dtohexstr(i);
	if (!str)
		return (0);
	count = 0;
	if (caseind == 0)
	{
		while (str[count])
		{
			str[count] = ft_tolower(str[count]);
			count++;
		}
	}
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	free (str);
	return (count);
}
