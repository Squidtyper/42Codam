/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 12:56:00 by lizhang       #+#    #+#                 */
/*   Updated: 2022/03/18 16:02:10 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	slen1;
	size_t	slen2;
	size_t	count;
	char	*strjoin;

	if (!str1 && !str2)
		return (NULL);
	slen1 = ft_strlen(str1);
	slen2 = ft_strlen(str2);
	strjoin = malloc((slen1 + slen2 + 1) * sizeof(char));
	count = 0;
	while (strjoin && count < slen1)
	{
		strjoin[count] = str1[count];
		count++;
	}
	count = 0;
	while (strjoin && count <= slen2)
	{
		strjoin[slen1 + count] = str2[count];
		count++;
	}
	if (str1)
		free(str1);
	return (strjoin);
}

int	ft_nl(char *str)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_strlen(str);
	if (!str)
		return (0);
	while (count < len)
	{
		if (str[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}

char	*ft_fstr(int fd, char *last)
{
	char		*fstr;
	char		temp[BUFFER_SIZE + 1];
	ssize_t		nread;

	fstr = ft_strjoin(NULL, last);
	nread = 1;
	temp[0] = '\0';
	while (ft_nl(fstr) == 0 && nread > 0)
	{
		nread = read (fd, temp, BUFFER_SIZE);
		if (nread < 0 || (nread == 0 && !temp[0] && !last[0]))
		{
			free(fstr);
			return (NULL);
		}
		temp[nread] = '\0';
		fstr = ft_strjoin(fstr, temp);
	}
	if (last[0] == '\0' && ft_strlen(fstr) == 0)
	{
		free(fstr);
		return (NULL);
	}
	return (fstr);
}

char	*ft_line(char *fstr)
{
	size_t	count;
	size_t	llen;
	char	*rline;

	count = 0;
	llen = 0;
	while (fstr[llen] != '\n' && fstr[llen])
		llen++;
	if (fstr[llen] == '\n')
		llen++;
	if (llen == 0)
		return (NULL);
	rline = malloc((llen + 1) * sizeof(char));
	if (!rline)
		return (NULL);
	while (count < llen)
	{
		rline[count] = fstr[count];
		count++;
	}
	rline[count] = '\0';
	return (rline);
}
