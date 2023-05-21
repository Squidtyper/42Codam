/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   strncmp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/13 17:08:30 by lizhang       #+#    #+#                 */
/*   Updated: 2021/05/13 17:24:23 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int c;
	int dif;

	c = 0;
	while (s1[c] != 0 && s2[c] != 0 && c < n)
	{
		dif = s1[c] - s2[c];
		if (dif != 0)
			break;
		c++;
	}
	return (dif);
}
