/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:26:44 by kglebows          #+#    #+#             */
/*   Updated: 2023/09/28 18:03:46 by kglebows         ###   ########.fr       */
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
				return (-10);
			i++;
		}
	}
	else
	{
		if (str[0] != '1' || str[map->width - 1] != '1')
			return (-9);
	}
	return (0);
}

int create_map(t_map *map)
{
	char		*str;
	int			i;

	i = 0;
	map->fd = open(map->path, 0);
	if (map->fd < 1)
		return (-8);
	map->map = (char **) calloc(map->height, sizeof(char *));
	if (!map->map)
		return (-12);
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
			return (-13);
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
			return (ft_printf("-> '%c' in line %d\n", *str, map->height) * 0 - 3);
		// ft_printf("scanning : %c\n", *str);
		str++;
	}
	if (map->E_num > 1)
		return (-4);
	if (map->P_num > 1)
		return (-5);
	return (0);
}

void	map_initial_values(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->C_num = 0;
	map->E_num = 0;
	map->P_num = 0;
}
int	map_ini(t_map *map)
{
	char		*str;

	map->fd = open(map->path, 0);
	if (map->fd < 0)
		return (-1);
	if (map->fd == 0)
		return (-11);
	map_initial_values(map);
	str = get_next_line(map->fd);
	map->width = ft_strlen_nl(str);
	while (1)
	{
		if (!str)
			break ;
		if (ft_strlen_nl(str) != map->width)
			return (-2);
		map->code = check_walls_topside(str, map);
		if (map->code < 0)
			return (map->code);
		map->height++;
		map->code = calculate_elements(str, map);
		if (map->code < 0)
			return (map->code);
		// ft_printf(".Hello there!.\n");
		str = get_next_line(map->fd);
	}
	if (map->height < 3 || map->width < 3)
		return (-6);
	if (map->C_num == 0)
		return (-7);
	if (map->E_num == 0)
		return (-14);
	if (map->P_num == 0)
		return (-15);
	close(map->fd);
	map->code = create_map(map);
	if (map->code < 0)
		return (map->code);
	// check if map is solvable
	return (0);
}

void	print_map(t_map *map)
{
	int			i;

	i = 0;
	while (i < map->height)
	{
		ft_printf("%s", map->map[i]);
		i++;
	}
}

int ft_error(int code)
{
	if (code == -1)
		return (ft_printf("Map data corrupted or missing!\n") * 0 + 2);
	else if (code == -2)
		return (ft_printf("Map data incorrect! Not a rectangle.\n") * 0 + 2);
	else if (code == -3)
		return (ft_printf("Map data incorrect! Characters other than allowed found.\n") * 0 + 2);
	else if (code == -4)
		return (ft_printf("Map data incorrect! More than one exit.\n") * 0 + 2);
	else if (code == -5)
		return (ft_printf("Map data incorrect! More than one player.\n") * 0 + 2);
	else if (code == -6)
		return (ft_printf("Map data incorrect! Map is too small.\n") * 0 + 2);
	else if (code == -7)
		return (ft_printf("Map data incorrect! Map is missing collectibles.\n") * 0 + 2);
	else if (code == -8)
		return (ft_printf("Map data access failed!\n") * 0 + 2);
	else if (code == -9)
		return (ft_printf("Map data incorrect! Map side walls incomplete.\n") * 0 + 2);
	else if (code == -10)
		return (ft_printf("Map data incorrect! Map top wall incomplete.\n") * 0 + 2);
	else if (code == -11)
		return (ft_printf("Map data empty!\n") * 0 + 2);
	else if (code == -12)
		return (ft_printf("Memory allocation for map failed!\n") * 0 + 2);
	else if (code == -13)
		return (ft_printf("Map data incorrect! Map bot wall incomplete.\n") * 0 + 2);
	else if (code == -14)
		return (ft_printf("Map data incorrect! Map is missing an Exit.\n") * 0 + 2);
	else if (code == -15)
		return (ft_printf("Map data incorrect! Map is missing a Player.\n") * 0 + 2);
	else
		return (ft_printf("Unknown Error! Please contact the developer.\n") * 0 + 2);
	//clean up : close fd if exists
}

int	main(int argn, char *argc[])
{
	t_map		map;

	if (argn < 2)
		return (ft_printf("Wrong input! Missing map path!\n") * 0 + 2);
	if (argn > 2)
		return (ft_printf("Wrong input! Too many arguments!\n") * 0 + 2);
	map.path = argc[1];
	map.code = map_ini(&map);
	// ft_printf(".Hello there!.\n");
	if (map.code < 0)
		return (ft_printf("!~ Map initialization Error :: ") * 0 + ft_error(map.code));
	ft_printf("Map %dx%d :: C.%d E.%d P.%d\n", map.width, map.height, map.C_num, map.E_num, map.P_num);
	print_map(&map);
	return (0);
}

