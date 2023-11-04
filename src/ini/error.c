/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:29:04 by kglebows          #+#    #+#             */
/*   Updated: 2023/11/04 18:11:07 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error__(int code)
{
	if (code == -23)
		ft_printf("Error! Map file name have to end with *.ber!\n");
	else
		ft_printf("Error! Please contact the developer.\n");
}

void error_(int code)
{
	if (code == -12)
		ft_printf("Error! Memory allocation failed!\n");
	else if (code == -13)
		ft_printf("Error! Map bot wall incomplete.\n");
	else if (code == -14)
		ft_printf("Error! Map is missing an Exit.\n");
	else if (code == -15)
		ft_printf("Error! Map is missing a Player.\n");
	else if (code == -16)
		ft_printf("Error! Memory allocation failed!\n");
	else if (code == -17)
		ft_printf("Error! Map is unsolvable.\n");
	else if (code == -18)
		ft_printf("Error! Wrong input! Missing map path!\n");
	else if (code == -19)
		ft_printf("Error! Wrong input! Too many arguments!\n");
	else if (code == -20)
		ft_printf("Error! MLX failure!\n");
	else if (code == -21)
		ft_printf("Error! MLX image generation failed!\n");
	else if (code == -22)
		ft_printf("Error! MLX image to window failure!\n");
	else
		error__(code);
}

void ft_error(int code, t_map *map)
{
	if (code == -1)
		ft_printf("Error! Map data corrupted or missing!\n");
	else if (code == -2)
		ft_printf("Error! Map is ot a rectangle.\n");
	else if (code == -3)
		ft_printf("Error! Map have forbidden Characters.\n");
	else if (code == -4)
		ft_printf("Error! More than one exit.\n");
	else if (code == -5)
		ft_printf("Error! More than one player.\n");
	else if (code == -6)
		ft_printf("Error! Map is too small.\n");
	else if (code == -7)
		ft_printf("Error! Map is missing collectibles.\n");
	else if (code == -8)
		ft_printf("Error! Map data access failed!\n");
	else if (code == -9)
		ft_printf("Error! Map side walls incomplete.\n");
	else if (code == -10)
		ft_printf("Error! Map top wall incomplete.\n");
	else if (code == -11)
		ft_printf("Error! Map data empty!\n");
	else
		error_(code);
	ft_exit(map);
}
