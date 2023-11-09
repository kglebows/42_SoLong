/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:26:27 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/09 13:29:09 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_elements(char *str, t_map *map)
{
	while (*str != '\n' && *str)
	{
		if (*str == 'C')
			map->c_num++;
		else if (*str == 'E')
			map->e_num++;
		else if (*str == 'P')
			map->p_num++;
		else if (*str == '0')
			;
		else if (*str == '1')
			map->w_num++;
		else
			ft_error(-3, map);
		str++;
	}
	if (map->e_num > 1)
		ft_error(-4, map);
	if (map->p_num > 1)
		ft_error(-5, map);
}

void	check_walls_topside(char *str, t_map *map)
{
	int			i;

	i = 0;
	if (map->height == 0)
	{
		while (i < map->width)
		{
			if (str[i] != '1')
				ft_error(-10, map);
			i++;
		}
	}
	else
	{
		if (str[0] != '1' || str[map->width - 1] != '1')
			ft_error(-9, map);
	}
}

void	map_check(t_map *map)
{
	char		*str;

	str = get_next_line(map->fd);
	map->width = ft_strlen_nl(str);
	while (str)
	{
		if (ft_strlen_nl(str) != map->width)
			ft_error(-2, map);
		check_walls_topside(str, map);
		map->height++;
		calculate_elements(str, map);
		free(str);
		str = get_next_line(map->fd);
	}
	free(str);
	if (map->height < 3 || map->width < 3)
		ft_error(-6, map);
	if (map->c_num == 0)
		ft_error(-7, map);
	if (map->e_num == 0)
		ft_error(-14, map);
	if (map->p_num == 0)
		ft_error(-15, map);
	close(map->fd);
}

void	check_ber(t_map *map)
{
	int			l;
	char		*s;

	s = map->path;
	l = ft_strlen(s) - 1;
	if (s[l - 3] != '.' || s[l - 2] != 'b' || s[l - 1] != 'e' || s[l] != 'r')
		ft_error(-23, map);
	map->fd = open(map->path, 0);
	if (map->fd < 0)
		ft_error(-1, map);
	if (map->fd == 0)
		ft_error(-11, map);
}

void	ft_ini(t_map *map)
{
	check_ber(map);
	map_check(map);
	ft_map(map);
	ft_image_map(map);
	ft_background_map(map);
}
