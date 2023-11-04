/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:40:21 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/04 17:47:57 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	ft_find_element(char **cpy, char c, t_map *map)
{
	t_position		pos;

	pos.x = 0;
	pos.y = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			if (cpy[pos.y][pos.x] == c)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	pos.x = -1;
	pos.y = -1;
	return (pos);
}

void	after_image(t_map *map)
{
	int			i;

	map->after_img = (mlx_image_t ***) ft_calloc(map->height,
					sizeof(mlx_image_t **));
	if (!map->after_img)
		ft_error(-12, map);
	i = 0;
	while (i < map->height)
	{
		map->after_img[i] = (mlx_image_t **) ft_calloc(map->width,
							sizeof(mlx_image_t *));
		if (!map->after_img[i])
			ft_error(-12, map);
		i++;
	}
}

void	ft_image_map(t_map *map)
{
	int				i;

	map->img_map = (mlx_image_t ***) ft_calloc(map->height,
					sizeof(mlx_image_t **));
	if (!map->img_map)
		ft_error(-12, map);
	i = 0;
	while (i < map->height)
	{
		map->img_map[i] = (mlx_image_t **) ft_calloc(map->width,
						sizeof(mlx_image_t *));
		if (!map->img_map[i])
			ft_error(-12, map);
		i++;
	}
	after_image(map);
}
