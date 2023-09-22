/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:26:44 by kglebows          #+#    #+#             */
/*   Updated: 2023/09/22 16:32:12 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argn, char *argc[])
{
	char		*str;
	int			fd;
	t_map		map;

	if (argn < 2)
		return (ft_printf("Wrong input! Missing map!\n") * 0 + 2);
	if (argn > 2)
		return (ft_printf("Wrong input! Too many arguments!\n") * 0 + 2);
	fd = open(argc[1], 0);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		line2map(str, &map);
	}
	close(fd);
	ft_printf("\n%dx%d", map.width, map.height);
	return (0);
}

int	line2map(char *str, t_map *map)
{
	ft_printf("%s", str);
	map->width = ft_strlen(str);
	map->height++;
	return (0);
}
