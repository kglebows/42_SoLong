/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 09:38:58 by kglebows          #+#    #+#             */
/*   Updated: 2023/10/21 10:40:36 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int seed(void)
{
	return (rand());
}

// unsigned int seed(void)
// {
// 	static unsigned int		rand = 141252362;
// 	rand++;
// 	return (rand);
// }

unsigned int	ft_random(unsigned int min, unsigned int max)
{
	int					lcg_multiplier;
	int					lcg_increment;
	int					lcg_modulus;
	unsigned int		random;

	lcg_multiplier = 1664525;
	lcg_increment = 1013904223;
	lcg_modulus = (int)pow(2, 32);
	random = (lcg_multiplier * seed() + lcg_increment) % lcg_modulus;
	random = (random % (max - min)) + min;
	return (random);
}