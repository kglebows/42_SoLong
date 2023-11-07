/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:03 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/07 19:26:30 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void animate(mlx_image_t **img, int maxf, int anim, t_map *map)
{
	int			frame;
	int			i;

	frame = map->time % maxf + anim;
	i = 0;
	while (i < 14)
	{
		if (img[i] != NULL && i == frame)
			img[i]->enabled = 1;
		else if (img[i] != NULL)
			img[i]->enabled = 0;
		i++;
	}
}

void	move(t_map *map)
{
	int			i;

	i = 0;
	while (i < 14)
	{
		map->img_map[0][0][i]->instances->x = map->P_pos.x * TILE_SIZE  + TILE_SIZE * 0.125;
		map->img_map[0][0][i]->instances->y = map->P_pos.y * TILE_SIZE + TILE_SIZE * 0.3;
		i++;
	}
	if (map->C_num < map->level)
		map->wall_map[0][0]->enabled = 1;
	map->wall_map[0][0]->instances->x = map->E_pos.x * TILE_SIZE;
	map->wall_map[0][0]->instances->y = map->E_pos.y * TILE_SIZE;
	if ( map->C_num < map->level && map->P_pos.x == map->E_pos.x && map->P_pos.y == map->E_pos.y )
	{
		map->jiggle = 2;
		if (map->endgame == 0)
			ft_put_string("U LOST!!! PRESS 'L'", map);
		map->endgame = 1;
	}
}

void	player(mlx_image_t **img, t_map *map)
{
	if (map->jiggle != 0)
	{
		animate(img, 7, 7, map);
		map->jiggle--;
	}
	else if (map->no != 0)
	{
		animate(img, 3, 3, map);
		map->no--;
	}
	else if (map->time % 50 < 7)
		animate(img, 7, 0, map);
	else
		animate(img, 1, 0, map);
}

void	portal(mlx_image_t **img, t_map *map)
{
	if (map->C_num == 0)
		animate(img, 4, 4, map);
	else
		animate(img, 4, 0, map);
}

void	Xcoin(mlx_image_t **img, int maxf)
{
	int			i;

	i = 0;
	while (i < maxf)
	{
		img[i]->enabled = 0;
		i++;
	}
}

void frame(t_map *map)
{
	int					x;
	int					y;

	player(map->img_map[0][0], map);
	move(map);
	x = 1;
	while (x < map->width - 1)
	{
		y = 1;
		while (y < map->height - 1)
		{
 			if (map->map[y][x] == 'E')
				portal(map->img_map[y][x], map);
			else if (map->map[y][x] == 'X')
				Xcoin(map->img_map[y][x], 6);
			else if (map->map[y][x] == 'C')
				animate(map->img_map[y][x], 6, 0, map);
			y++;
		}
		x++;
	}
}

void ft_frame(void *param)
{

	static double	time = 0;
	t_map			*map;

	map = (t_map *)param;
	time = time + map->mlx->delta_time;
	if (time >= 0.06)
	{
		time = 0;
		map->time++;
		frame(map);
	}
	if (map->time > 630)
		map->time = 0;
}
