/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:23:07 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/07 17:48:27 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void ft_free_map(t_map *map)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < map->width - 1)
// 	{
// 		j = 0;
// 		while (j < map->height - 1)
// 		{
// 			if (map->after_img[i][j] != NULL)
// 			{
// 				mlx_delete_image(map->mlx, map->after_img[i][j]);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void ft_after_img(t_map *map)
// {
// 	int i;
// 	int j;

// 	if (map->img_map[0][0] != NULL)
// 	{
// 		map->after_img[0][0] = map->img_map[0][0];
// 		mlx_delete_image(map->mlx, map->img_map[0][0]);
// 	}
// 	i = 1;
// 	while (i < map->width - 1)
// 	{
// 		j = 1;
// 		while (j < map->height - 1)
// 		{
// 			if (map->img_map[i][j] != NULL)
// 			{
// 				map->after_img[i][j] = map->img_map[i][j];
// 				mlx_delete_image(map->mlx, map->img_map[i][j]);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

void ft_restart_map(t_map *map)
{
	int i;
	int j;

	i = 1;
	while (i < map->width - 1)
	{
		j = 1;
		while (j < map->height - 1)
		{
			if (map->map[j][i] == 'X')
				map->map[j][i] = 'C';
			j++;
		}
		i++;
	}
	// mlx_delete_image(map->mlx, map->img_map[0][1]);
	map->wall_map[0][0]->enabled = 0;
	map->C_num = map->level;
	map->level = 0;
	map->E_pos = ft_pos(1, 1);
	map->P_pos = ft_find_element(map->map, 'P', map);
	map->steps = 0;
	map->endgame = 0;
	ft_put_string_inventory(map);
	ft_put_string("    GET COINS!!!", map);
}
