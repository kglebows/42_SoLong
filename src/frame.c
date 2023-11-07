/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:03 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/07 13:52:41 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void frame_put(mlx_image_t ***img, t_map *map)
{
	int			i;
	int			j;

	img[0][0] = ft_put_imp(map);
	i = 1;
	while (i < map->width - 1)
	{
		j = 1;
		while (j < map->height - 1)
		{

 			if (map->map[j][i] == 'E')
				img[i][j] = ft_put_exit(i, j, map);
			else if (map->map[j][i] == 'C')
				img[i][j] = ft_put_coin(i, j, map);
			j++;
		}
		i++;
	}
}

void frame_enemy(t_map *map)
{
	if (map->level > map->C_num)
	{
		if (map->P_pos.x == map->E_pos.x && map->P_pos.y == map->E_pos.y )
		{
			map->jiggle = 2;
			if (map->endgame == 0)
				ft_put_string("U LOST!!! PRESS 'L'", map);
			map->endgame = 1;
		}
	}
}

void frame_clear(mlx_image_t ***img, t_map *map)
{
	int i;
	int j;

	if (img[0][0] != NULL)
		mlx_delete_image(map->mlx, img[0][0]);
	i = 1;
	while (i < map->width - 1)
	{
		j = 1;
		while (j < map->height - 1)
		{
			if (img[i][j] != NULL)
				mlx_delete_image(map->mlx, img[i][j]);
			j++;
		}
		i++;
	}
}

//
#include <stdio.h>
//

void ft_frame(void *param)
{

	static double	time = 0;
	t_map			*map;

	map = (t_map *)param;
	time = time + map->mlx->delta_time;
	//
	printf("%d :: %f :: %f\n", map->frame, time, map->mlx->delta_time);
	//
	if (time >= 0.0615)
	{
		time = 0;
		map->time++;
		if (map->time % 2 == 0)
			map->frame++;
		if (map->time % 4 == 1)
			frame_put(map->img_map, map);
		if (map->time % 4 == 2)
			frame_clear(map->after_img, map);
		if (map->time % 4 == 3)
			frame_put(map->after_img, map);
		if (map->time % 4 == 0)
			frame_clear(map->img_map, map);

			
		// if (map->time % 2 == 1)
		// {
		// 	frame_put(map->img_map, map);
		// 	frame_clear(map->after_img, map);
		// 	// map->frame++;
		// }
		// else
		// {
		// 	frame_put(map->after_img, map);
		// 	frame_clear(map->img_map, map);
		// 	// map->frame++;
		// }
		frame_enemy(map);
	}

		
	if (map->time > 1260)
		map->time = 0;
	if (map->frame > 630)
		map->frame = 0;
}
