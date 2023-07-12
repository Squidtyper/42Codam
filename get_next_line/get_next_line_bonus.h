/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/04 21:03:33 by lizhang       #+#    #+#                 */
/*   Updated: 2022/03/13 20:22:32 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
int		ft_nl(char *str);
char	*ft_line(char *fstr);
char	*ft_fstr(int fd, char *last);
#endif
