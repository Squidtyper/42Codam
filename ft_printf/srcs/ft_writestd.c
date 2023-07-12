/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writestd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/27 20:41:35 by lizhang       #+#    #+#                 */
/*   Updated: 2021/11/02 21:54:37 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printflibft.h"

int	ft_writestd(const char *str)
{
	int	count;

	if (str[0] == 0)
		return (0);
	count = 0;
	while (str[count])
	{
		if (str[count] == '%')
			return ((count));
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}
