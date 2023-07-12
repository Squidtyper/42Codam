/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 15:48:33 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/12 15:49:58 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd1;
	char	*str;

	fd1 = open(av[1], O_RDONLY);
	ac = 0;
	while ((str = get_next_line(fd1)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	// str = get_next_line(0);
	// printf("%s", str);
	free (str);
	system("leaks get_next_line");
	return (0);
}
