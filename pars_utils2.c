/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:35:15 by yzoullik          #+#    #+#             */
/*   Updated: 2025/02/09 14:07:45 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(char **ptr, int y, int x, int *c)
{
	if (ptr[y][x] == '1' || ptr[y][x] == 'X')
		return ;
	if (ptr[y][x] == 'E')
		(*c)++;
	ptr[y][x] = 'X';
	ft_floodfill(ptr, y + 1, x, c);
	ft_floodfill(ptr, y - 1, x, c);
	ft_floodfill(ptr, y, x + 1, c);
	ft_floodfill(ptr, y, x - 1, c);
	return ;
}

int	ft_isaccess(char	**ptr)
{
	int	x;
	int	y;
	int	c;

	x = 0;
	y = 0;
	c = 0;
	playerpos(ptr, &y, &x);
	ft_floodfill(ptr, y, x, &c);
	if (c == 1)
		return (1);
	return (0);
}

int	closew(t_list **list)
{
	clear_all(list);
	exit(0);
	return (0);
}

void	textures_init(t_list **list)
{
	int	s;

	s = 64;
	(*list)->wall = mlx_xpm_file_to_image((*list)->mlx, \
	"./textures/1.xpm", &s, &s);
	(*list)->space = mlx_xpm_file_to_image((*list)->mlx, \
	"./textures/0.xpm", &s, &s);
	(*list)->coll = mlx_xpm_file_to_image((*list)->mlx, \
	"./textures/C.xpm", &s, &s);
	(*list)->exit = mlx_xpm_file_to_image((*list)->mlx, \
	"./textures/E.xpm", &s, &s);
	(*list)->player = mlx_xpm_file_to_image((*list)->mlx, \
	"./textures/P.xpm", &s, &s);
}
