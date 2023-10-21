/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:26:27 by kglebows          #+#    #+#             */
/*   Updated: 2023/10/21 12:29:49 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calculate_elements(char *str, t_map *map)
{
	while (*str != '\n' && *str)
	{
		if (*str == 'C')
			map->C_num++;
		else if (*str == 'E')
			map->E_num++;
		else if (*str == 'P')
			map->P_num++;
		else if (*str == '0')
			;
		else if (*str == '1')
			;
		else
			return (ft_printf("-> '%c' in line %d\n", *str, map->height) * 0 + ft_error(-3));
		str++;
	}
	if (map->E_num > 1)
		return (ft_error(-4));
	if (map->P_num > 1)
		return (ft_error(-5));
	return (0);
}

int	check_walls_topside(char *str, t_map *map)
{
	int			i;

	i = 0;
	if (map->height == 0)
	{
		while (i < map->width)
		{
			if (str[i] != '1')
				return (ft_error(-10));
			i++;
		}
	}
	else
	{
		if (str[0] != '1' || str[map->width - 1] != '1')
			return (ft_error(-9));
	}
	return (0);
}

int	map_check(t_map *map)
{
	char		*str;

	str = get_next_line(map->fd);
	map->width = ft_strlen_nl(str);
	while (str)
	{
		if (ft_strlen_nl(str) != map->width)
			return (ft_error(-2));
		if (check_walls_topside(str, map) != 0)
			return (2);
		map->height++;
		if (calculate_elements(str, map) != 0)
			return (2);
		str = get_next_line(map->fd);
	}
	if (map->height < 3 || map->width < 3)
		return (ft_error(-6));
	if (map->C_num == 0)
		return (ft_error(-7));
	if (map->E_num == 0)
		return (ft_error(-14));
	if (map->P_num == 0)
		return (ft_error(-15));
	close(map->fd);
	return (0);
}

int	map_initial_values(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->C_num = 0;
	map->E_num = 0;
	map->P_num = 0;
	map->fd = open(map->path, 0);
	if (map->fd < 0)
		return (ft_error(-1));
	if (map->fd == 0)
		return (ft_error(-11));
	return (0);
}

int	ft_ini(t_map *map)
{
	if (map_initial_values(map) != 0)
		return (2);
	if (map_check(map) != 0)
		return (2);
	if (ft_map(map) != 0)
		return (2);
	if (ft_image_map(map) != 0)
		return (2);
	return (0);
}
