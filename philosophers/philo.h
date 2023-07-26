/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 00:33:28 by lizhang       #+#    #+#                 */
/*   Updated: 2022/10/28 22:01:42 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h> 

//0 for death, 1 for eating, 2 for sleeping, 3 for thinking
typedef struct s_philo
{
	pthread_t		tid;
	int				id;
	int				chop1;
	int				chop2;
	long long		lastmeal;
	int				state;
	int				fin;
	pthread_mutex_t	fmutex;
	pthread_mutex_t	lmutex;
	struct s_group	*group;
}			t_philo;

typedef struct s_group
{
	int				n;
	long long		ttd;
	long long		tte;
	long long		tts;
	int				xtimes;
	long long		time0;
	t_philo			*philo;
	pthread_mutex_t	*chops;
	int				dead;
	pthread_mutex_t	dmutex;
	pthread_t		checkdeath;
}			t_group;

//utils
int			aton(const char *str);
long long	gettime(long long time0);
void		joinall(t_group *g);
void		stepsleep(long long time);

//philo info
void		philo_gen(t_group *g);
void		mutex_gen(t_group *g);
t_group		*parseinput(int ac, char **av);

//errors
int			acerror(int ac);
int			averror(char **av);
int			nerror(t_group *g);

//philo actions
int			unlock(t_philo *philo);
void		lonely(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

//check
int			checkfinish(t_group *g);
void		*checkdeath(void *group);

//access
long long	accessmeal(t_philo *philo, int r, long long replace);
int			accessd(t_group *g, int r);
int			accessf(t_philo *philo, int r);

//end
void		mutexdestroy(t_group *g);
void		freeall(t_group *g);

//main
void		mainsleep(t_group *g);
void		*loop(void *varg);
void		thread(t_group *g);

//void	mainsleep(t_group *g);
#endif