/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:22:50 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/07 18:33:49 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	difficulty(t_map *map)
{
	int			temp;

	if (map->difficulty == 0)
		return (map->C_num + 1);
	else
	{
		temp = map->C_num - map->difficulty;
		if (temp < 0)
			temp = 0;
		return (temp + 1);
	}
}

void	ft_move_enemy(t_map *map)
{
	t_position	pos;

	pos = ft_pos_dist(map->E_pos, map->P_pos);

	if (pos.x > 0)
		pos = ft_pos(-1, 0);
	else if (pos.x < 0)
		pos = ft_pos(1, 0);
	else if (pos.y > 0)
		pos = ft_pos(0, -1);
	else if (pos.y < 0)
		pos = ft_pos(0, 1);
	if (map->level > map->C_num && ft_random(0, difficulty(map)) == 1)
		map->E_pos = ft_pos_add(map->E_pos, pos);
}
