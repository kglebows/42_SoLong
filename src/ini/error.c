/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:29:04 by kglebows          #+#    #+#             */
/*   Updated: 2023/09/29 17:07:54 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (code == -16)
		return (ft_printf("Memory allocation for map copy failed!\n") * 0 + 2);
	else if (code == -17)
		return (ft_printf("Map data incorrect! Map is unsolvable.\n") * 0 + 2);
	else if (code == -18)
		return (ft_printf("Wrong input! Missing map path!\n") * 0 + 2);
	else if (code == -19)
		return (ft_printf("Wrong input! Too many arguments!\n") * 0 + 2);
	else if (code == -20)
		return (ft_printf("MLX gone bad! brrrr bww bum pfff pstttt trrr. it's dead.\n:'(\n") * 0 + 2);
	else if (code == -21)
		return (ft_printf("MLX gone bad! image generation failed!\n:'(\n") * 0 + 2);
	else
		return (ft_printf("Unknown Error! Please contact the developer.\n") * 0 + 2);
	//clean up : close fd if exists
}