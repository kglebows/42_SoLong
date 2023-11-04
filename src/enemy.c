/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:22:50 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/04 16:55:57 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (map->level > map->C_num && ft_random(0, map->C_num + 1) == 1)
		map->E_pos = ft_pos_add(map->E_pos, pos);
	if (map->level > map->C_num)
		ft_put_enemy(map);
}
