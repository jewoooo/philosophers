/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 11:07:07 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/03 23:07:58 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	philo_print(char *s, t_philo *philo)
{
	sem_wait(philo->print_sem);
	printf("%ld %d %s\n", gettime() - philo->launch_time,
		philo->id, s);
	sem_post(philo->print_sem);
}

void	philo_sleep(long sleep_time)
{
	long	start;

	start = gettime();
	while (gettime() - start < sleep_time)
		usleep(500);
}
