/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjupar <minjupar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:13:40 by minjupar          #+#    #+#             */
/*   Updated: 2022/04/05 03:18:50 by minjupar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define TRUE 1;
# define FALSE 0;
# define DELAY 1000;

typedef pthread_t		t_th;
typedef pthread_mutex_t	t_mutex;
typedef struct s_philo	t_philo;
typedef struct s_info	t_info;

typedef struct s_philo
{
	int		id;
	int		current_eat_cnt;
	time_t	time_die;
	t_th	thread;
	t_th	die_monitor;
	t_info	*info;
	t_mutex	fork;
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	t_mutex	eating;

}				t_philo;

typedef struct s_info
{
	int		philo_num;
	int		must_eat;
	int		fin_eat_cnt;
	int		is_finished;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	t_th	must_eat_monitor;
	t_mutex	print_mutex;
	t_philo	*philos;

}				t_info;

int		ft_atoi(const char *str);
void	ft_printf(char *str, t_philo *philo, time_t now);

time_t	get_time(void);
void	time_flow(time_t start_time, time_t target_time);

int		init_philo(t_info *info);
int		init_info(int argc, char **argv, t_info *info);

void	*philo_routine(void *arg);
void	*putdown(t_philo *philo);
void	*pickup(t_philo *philo);
void	*eating(t_philo *philo);
void	*thinking(t_philo *philo);
void	*sleeping(t_philo *philo);
void	*die_monitor(void *arg);
void	*must_eat_monitor(void *arg);

#endif
