/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:27:03 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/09 13:34:31 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player(mlx_image_t **img, t_map *map)
{
	if (map->jiggle != 0)
	{
		ft_animate(img, 7, 7, map);
		map->jiggle--;
	}
	else if (map->no != 0)
	{
		ft_animate(img, 3, 3, map);
		map->no--;
	}
	else if (map->time % 100 < 14)
		ft_animate(img, 7, 0, map);
	else
		ft_animate(img, 1, 0, map);
}

void	portal(mlx_image_t **img, t_map *map)
{
	if (map->c_num == 0)
		ft_animate(img, 4, 4, map);
	else
		ft_animate(img, 4, 0, map);
}

void	xcoin(mlx_image_t **img, int maxf)
{
	int			i;

	i = 0;
	while (i < maxf)
	{
		img[i]->enabled = 0;
		i++;
	}
}

void	frame(t_map *map)
{
	int					x;
	int					y;

	player(map->img_map[0][0], map);
	ft_move_pos(map);
	x = 1;
	while (x < map->width - 1)
	{
		y = 1;
		while (y < map->height - 1)
		{
			if (map->map[y][x] == 'E')
				portal(map->img_map[y][x], map);
			else if (map->map[y][x] == 'X')
				xcoin(map->img_map[y][x], 6);
			else if (map->map[y][x] == 'C')
				ft_animate(map->img_map[y][x], 6, 0, map);
			y++;
		}
		x++;
	}
}

void	ft_frame(void *param)
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
