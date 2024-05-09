/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behave_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:52:56 by jewlee            #+#    #+#             */
/*   Updated: 2024/05/09 15:27:55 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	philo_print(char *s, t_philo *philo)
{
	t_info	*info;

	if (check_died(philo) == TRUE)
		return (FAIL);
	info = philo->info;
	pthread_mutex_lock(&(info->print_mutex));
	printf("%ld %d %s\n", gettime() - info->launch_time,
		philo->id, s);
	pthread_mutex_unlock(&(info->print_mutex));
	return (SUCCESS);
}

int	philo_sleep(long start, t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	while (gettime() - start < info->time_to_sleep)
	{
		if (check_died(philo) == TRUE)
			return (FAIL);
	}
	return (SUCCESS);
}
