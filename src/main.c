/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:26:44 by kglebows          #+#    #+#             */
/*   Updated: 2023/09/28 20:00:21 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	create_map(t_map *map)
{
	char		*str;
	int			i;

	i = 0;
	map->fd = open(map->path, 0);
	if (map->fd < 1)
		return (ft_error(-8));
	map->map = (char **) calloc(map->height, sizeof(char *));
	if (!map->map)
		return (ft_error(-12));
	while (i < map->height)
	{
		str = get_next_line(map->fd);
		map->map[i] = str;
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (str[i] != '1')
			return (ft_error(-13));
		i++;
	}
	close(map->fd);
	return (0);
}

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

void	print_map(t_map *map)
{
	int			i;

	i = 0;
	ft_printf("Map %dx%d :: C.%d E.%d P.%d\n", map->width, map->height, map->C_num, map->E_num, map->P_num);
	while (i < map->height)
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
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

void	flood(int y, int x, char **cpy)
{
	if (cpy[y][x] != '1' && cpy[y][x] != 'F')
	{
		cpy[y][x] = 'F';
		flood(y + 1, x, cpy);
		flood(y - 1, x, cpy);
		flood(y, x + 1, cpy);
		flood(y, x - 1, cpy);
	}
}

void	map_flood(char **cpy, t_map *map)
{
	t_position			pos;

	pos.y = 0;
	while (pos.y < map->height)
	{
		pos.x = 0;
		while (pos.x < map->width)
		{
			if (cpy[pos.y][pos.x] == 'P')
				flood(pos.y, pos.x, cpy);
			pos.x++;
		}
		pos.y++;
	}
}

int	check_for_C(char **cpy, t_map *map)
{
	int			i;
	int			j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (cpy[i][j] == 'C')
				return (-17);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_flood_solve(t_map *map)
{
	char		**cpy;
	int			i;

	cpy = (char **) calloc(map->height, sizeof(char *));
	if (!cpy)
		return (ft_error(-16));
	i = 0;
	while (i < map->height)
	{
		cpy[i] = ft_strdup(map->map[i]);
		i++;
	}
	map_flood(cpy, map);
	if (check_for_C(cpy, map) < 0)
		return (ft_error(-17));
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

int	map_ini(t_map *map)
{
	if (map_initial_values(map) != 0)
		return (2);
	if (map_check(map) != 0)
		return (2);
	if (create_map(map) != 0)
		return (2);
	if (map_flood_solve(map) != 0)
		return (2);
	return (0);
}

int	main(int argn, char *argc[])
{
	t_map		map;

	if (argn < 2)
		return (ft_error(-18));
	if (argn > 2)
		return (ft_error(-19));
	map.path = argc[1];
	if (map_ini(&map)!= 0)
		return (2);
	print_map(&map);
	return (0);
}

