/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:22:50 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/09 13:27:57 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	difficulty(t_map *map)
{
	int			temp;

	if (map->difficulty == 0)
		return (map->c_num + 1);
	else
	{
		temp = map->c_num - map->difficulty;
		if (temp < 0)
			temp = 0;
		return (temp + 1);
	}
}

void	ft_levelup_enemy(t_map *map)
{
	mlx_delete_image(map->mlx, map->wall_map[0][0]);
	map->difficulty = map->level;
	ft_put_enemy(map);
	ft_put_string("       RUN!!!", map);
}

void	ft_move_enemy(t_map *map)
{
	t_position	pos;

	pos = ft_pos_dist(map->e_pos, map->p_pos);
	if (pos.x > 0)
		pos = ft_pos(-1, 0);
	else if (pos.x < 0)
		pos = ft_pos(1, 0);
	else if (pos.y > 0)
		pos = ft_pos(0, -1);
	else if (pos.y < 0)
		pos = ft_pos(0, 1);
	if (map->level > map->c_num && ft_random(0, difficulty(map)) == 1)
		map->e_pos = ft_pos_add(map->e_pos, pos);
}
