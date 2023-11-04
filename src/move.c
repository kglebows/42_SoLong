/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/04 18:30:01 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_wall(t_map *map)
{
	map->jiggle = 0;
	map->no = 3;
	ft_printf("WALL\n");
	ft_move_enemy(map);
}

void	move_free(t_position pos, t_map *map)
{
	map->no = 0;
	map->jiggle = 2;
	map->P_pos = pos;
	ft_printf("-> %d:%d\n", pos.x, pos.y);
	ft_move_enemy(map);
}

void	move_coin(t_position pos, t_map *map)
{
	map->no = 0;
	map->P_pos = pos;
	map->jiggle = 6;
	map->map[pos.y][pos.x] = 'X';
	mlx_delete_image(map->mlx, map->img_map[pos.x][pos.y]);
	if (map->level == 0)
	{
		map->level = map->C_num;
		ft_put_string("DON'T GET CAUGHT!!!", map);
	}
	map->C_num--;
	if (map->C_num == 0)
		ft_put_string("  GO TO PORTAL!!!", map);
	ft_printf("COIN! %d:%d\n", pos.x, pos.y);
	ft_move_enemy(map);
}

void	move_exit(t_position pos, t_map *map)
{
	if (map->C_num != 0)
	{
		map->P_pos = pos;
		map->jiggle = 0;
		map->no = 10000;
		ft_printf("EXIT\n");
	}
	else
	{
		map->no = 0;
		map->P_pos = pos;
		map->jiggle = 10000;
		ft_printf("EXIT\n");
		ft_put_string("U WON!!! PRESS 'E'", map);
		map->endgame = 1;
	}
}

void	ft_move(t_position pos, t_map *map)
{
	map->steps++;
	ft_printf("MOVE %d :", map->steps);
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
