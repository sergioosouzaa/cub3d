/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdos-san <sdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:28:04 by sdos-san          #+#    #+#             */
/*   Updated: 2023/03/13 11:29:02 by sdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

/* initialize the seed to the random funciton */

void	initialize_chaos(void)
{
	time_t	t;

	srand((unsigned) time(&t));
}

/*  Get the time at the start of the program, so
it can know the that that passed while it was running */

long long	get_first_time(void)
{
	struct timeval	first;

	gettimeofday(&first, NULL);
	return ((first.tv_sec) * 1000 + (first.tv_usec) * 0.001);
}

/* Return the time passed after the program has started */

long long	time_return(long long first_time)
{
	struct timeval	first;
	long long		actual_time;

	gettimeofday(&first, NULL);
	actual_time = (first.tv_sec) * 1000 + (first.tv_usec) * 0.001;
	return (actual_time - first_time);
}
