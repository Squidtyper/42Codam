/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 00:58:28 by lizhang       #+#    #+#                 */
/*   Updated: 2022/10/29 16:11:42 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mainsleep(t_group *g)
{
	usleep(100);
	while (checkfinish(g) < 0 && accessd(g, 0) == 1)
		usleep(500);
	if (checkfinish(g) > 0)
		printf("cycle has finished");
}

void	*loop(void *varg)
{
	t_philo	*philo;

	philo = (t_philo *)varg;
	if (philo->id % 2 == 1)
		usleep(100000);
	while (checkfinish(philo->group) < 0 && accessd(philo->group, 0) == 1)
	{
		if (philo->group->n == 1)
			lonely(philo);
		if (philo->state == 3)
			eating(philo);
		else if (philo->state == 1)
			sleeping(philo);
		else if (philo->state == 2)
			thinking(philo);
	}
	return (NULL);
}

void	thread(t_group *g)
{
	int	i;

	i = 0;
	while (i < g->n)
	{
		if (pthread_create(&(g->philo[i].tid), NULL, loop, \
		(void *)&(g->philo[i])) < 0)
			return ;
		i++;
	}
	if (pthread_create(&(g->checkdeath), NULL, checkdeath, (void *)g) < 0)
		return ;
	joinall(g);
	pthread_join(g->checkdeath, NULL);
}

int	main(int ac, char **av)
{
	t_group	*g;

	g = parseinput(ac, av);
	if (!g)
		return (0);
	philo_gen(g);
	mutex_gen(g);
	if (!g->philo || !g->chops)
		return (0);
	thread(g);
	mainsleep(g);
	mutexdestroy(g);
	freeall(g);
	return (0);
}
