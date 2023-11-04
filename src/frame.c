/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:03 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/04 19:31:39 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void frame_map(t_map *map)
{
	int			i;
	int			j;

	if (map->img_map[0][0])
		mlx_delete_image(map->mlx, map->img_map[0][0]);
	map->img_map[0][0] = ft_put_imp(map);
	i = 1;
	while (i < map->width - 1)
	{
		j = 1;
		while (j < map->height - 1)
		{

 			if (map->map[j][i] == 'E')
			{
				if (map->img_map[i][j])
					mlx_delete_image(map->mlx, map->img_map[i][j]);
				map->img_map[i][j] = ft_put_exit(i, j, map);
			}
			else if (map->map[j][i] == 'C')
			{
				if (map->img_map[i][j])
					mlx_delete_image(map->mlx, map->img_map[i][j]);
				map->img_map[i][j] = ft_put_coin(i, j, map);
			}
			j++;
		}
		i++;
	}
	if (map->level > map->C_num)
	{
		// map->img_map[0][1] = ft_put_enemy(map);
		if (map->P_pos.x == map->E_pos.x && map->P_pos.y == map->E_pos.y )
		{
			map->jiggle = 2;
			if (map->endgame == 0)
				ft_put_string("U LOST!!! PRESS 'L'", map);
			map->endgame = 1;
		}
	}
}

#include <stdio.h>
void ft_frame(void *param)
{

	static double	time = 0;
	t_map			*map;

	map = (t_map *)param;
	time = time + map->mlx->delta_time;
	printf("%d :: %f\n", map->time, time);
	if (time >= 0.1)
	{
		time = 0;
		map->time++;
		map->frame++;
		frame_map(map);
		ft_free_map(map);
	}
	

		
	if (map->time > 603)
		map->time = 0;
	if (map->frame > 12)
		map->frame = 0;
}
