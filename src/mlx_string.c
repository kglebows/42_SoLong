/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:17:48 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/07 17:03:46 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_string_steps(t_map *map)
{
	char		*str[2];

	if (map->wall_map[0][3])
		mlx_delete_image(map->mlx, map->wall_map[0][3]);
	str[0] = ft_itoa(map->steps);
	str[1] = ft_strjoin(" ->", str[0]);
	free(str[0]);
	map->wall_map[0][3] = mlx_put_string(map->mlx, str[1], 0,
						(map->height - 0.5) * TILE_SIZE);
	free(str[1]);
}

void ft_put_string_inventory(t_map *map)
{
	char		*str[3];

	put_string_steps(map);
	if (map->wall_map[0][2])
		mlx_delete_image(map->mlx, map->wall_map[0][2]);
	str[0] = ft_itoa(map->C_num + map->W_num - map->height * 2 -
					(map->width - 2) * 2);
	str[1] = ft_itoa((map->width - 1) * (map->height - 1));
	str[2] = ft_strjoin("Inv : ", str[0]);
	free(str[0]);
	str[0] = ft_strjoin("/", str[1]);
	free(str[1]);
	str[1] = ft_strjoin(str[2], str[0]);
	free(str[2]);
	free(str[0]);
	map->wall_map[0][2] = mlx_put_string(map->mlx, str[1],
				(map->width - 2) * TILE_SIZE, (map->height - 0.5) * TILE_SIZE);
	free(str[1]);
}

void ft_put_string(char *str, t_map *map)
{
	if (map->wall_map[2][0])
		mlx_delete_image(map->mlx, map->wall_map[2][0]);
	map->wall_map[2][0] = mlx_put_string(map->mlx, str,
						(map->width - 3) / 2 * TILE_SIZE, 0.15 * TILE_SIZE);
}
