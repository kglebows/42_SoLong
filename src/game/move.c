/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/09 13:51:17 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_wall(t_map *map)
{
	map->jiggle = 0;
	map->no = 3;
	ft_move_enemy(map);
}

void	move_free(t_position pos, t_map *map)
{
	map->no = 0;
	map->jiggle = 2;
	map->p_pos = pos;
	ft_move_enemy(map);
}

void	move_coin(t_position pos, t_map *map)
{
	map->no = 0;
	map->p_pos = pos;
	map->jiggle = 6;
	map->map[pos.y][pos.x] = 'X';
	if (map->level == 0)
	{
		map->level = map->c_num;
		ft_put_string("DON'T GET CAUGHT!!!", map);
	}
	ft_move_enemy(map);
	map->c_num--;
	if (map->c_num == 0)
		ft_put_string("  GO TO PORTAL!!!", map);
}

void	move_exit(t_position pos, t_map *map)
{
	if (map->c_num != 0)
	{
		map->p_pos = pos;
		map->jiggle = 0;
		map->no = 10000;
	}
	else
	{
		map->no = 0;
		map->p_pos = pos;
		map->jiggle = 10000;
		ft_put_string("U WON!!! PRESS 'E'", map);
		map->endgame = 1;
	}
}

void	ft_move(t_position pos, t_map *map)
{
	map->steps++;
	if (map->map[pos.y][pos.x] == '1')
		move_wall(map);
	else if (map->map[pos.y][pos.x] == '0')
		move_free(pos, map);
	else if (map->map[pos.y][pos.x] == 'P')
		move_free(pos, map);
	else if (map->map[pos.y][pos.x] == 'X')
		move_free(pos, map);
	else if (map->map[pos.y][pos.x] == 'C')
		move_coin(pos, map);
	else if (map->map[pos.y][pos.x] == 'E')
		move_exit(pos, map);
	ft_put_string_inventory(map);
}
