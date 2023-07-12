/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 21:07:45 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/12 15:48:55 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//using "ulimit -n" on mac to see the max number of file descriptors

char	*get_next_line(int fd)
{
	char		*fstr;
	static char	last[8192][BUFFER_SIZE + 1];
	size_t		nxt;
	size_t		count;
	char		*rline;

	if (fd < 0)
		return (NULL);
	fstr = ft_fstr(fd, last[fd]);
	if (!fstr)
		return (NULL);
	rline = ft_line(fstr);
	nxt = ft_strlen(rline);
	count = 0;
	while (fstr[nxt + count])
	{
		last[fd][count] = fstr[nxt + count];
		count++;
	}
	last[fd][count] = '\0';
	free(fstr);
	return (rline);
}
