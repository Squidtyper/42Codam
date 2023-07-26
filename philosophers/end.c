/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 21:04:41 by lizhang       #+#    #+#                 */
/*   Updated: 2022/10/28 21:05:30 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutexdestroy(t_group *g)
{
	int	i;

	i = 0;
	while (i < g->n)
	{
		pthread_mutex_destroy(&g->chops[i]);
		pthread_mutex_destroy(&g->philo[i].fmutex);
		pthread_mutex_destroy(&g->philo[i].lmutex);
		i++;
	}
	pthread_mutex_destroy(&g->dmutex);
}

void	freeall(t_group *g)
{
	free(g->philo);
	free(g->chops);
	free(g);
}
