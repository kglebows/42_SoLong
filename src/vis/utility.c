/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:23:07 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/09 13:39:16 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_animate(mlx_image_t **img, int maxf, int anim, t_map *map)
{
	int			frame;
	int			i;

	frame = map->time % maxf + anim;
	i = 0;
	while (i < 16)
	{
		if (img[i] != NULL && i == frame)
			img[i]->enabled = 1;
		else if (img[i] != NULL)
			img[i]->enabled = 0;
		i++;
	}
}

void	ft_move_pos(t_map *map)
{
	int			i;

	i = 0;
	while (i < 14)
	{
		map->img_map[0][0][i]->instances->x
			= map->p_pos.x * TILE_SIZE + TILE_SIZE * 0.125;
		map->img_map[0][0][i]->instances->y
			= map->p_pos.y * TILE_SIZE + TILE_SIZE * 0.3;
		i++;
	}
	if (map->c_num < map->level)
		map->wall_map[0][0]->enabled = 1;
	if (map->difficulty == 0 && map->c_num < map->level / 2)
		ft_levelup_enemy(map);
	map->wall_map[0][0]->instances->x = map->e_pos.x * TILE_SIZE;
	map->wall_map[0][0]->instances->y = map->e_pos.y * TILE_SIZE;
	if (map->c_num < map->level && map->p_pos.x == map->e_pos.x
		&& map->p_pos.y == map->e_pos.y)
	{
		map->jiggle = 2;
		if (map->endgame == 0)
			ft_put_string("U LOST!!! PRESS 'L'", map);
		map->endgame = 1;
	}
}

void	ft_restart_map(t_map *map)
{
	int	i[2];

	i[0] = 1;
	while (i[0] < map->width - 1)
	{
		i[1] = 1;
		while (i[1] < map->height - 1)
		{
			if (map->map[i[1]][i[0]] == 'X')
				map->map[i[1]][i[0]] = 'C';
			i[1]++;
		}
		i[0]++;
	}
	map->c_num = map->level;
	map->level = 0;
	map->difficulty = 0;
	map->e_pos = ft_pos(1, 1);
	map->p_pos = ft_find_element(map->map, 'P', map);
	map->steps = 0;
	map->endgame = 0;
	mlx_delete_image(map->mlx, map->wall_map[0][0]);
	ft_put_enemy(map);
	ft_put_string_inventory(map);
	ft_put_string("    GET COINS!!!", map);
}
