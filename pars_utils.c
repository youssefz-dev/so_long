/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:51:12 by yzoullik          #+#    #+#             */
/*   Updated: 2025/02/11 15:51:37 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ismapchr(char *ptr, int *c, int *e, int *p)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == 'C')
			(*c)++;
		if (ptr[i] == 'E')
			(*e)++;
		if (ptr[i] == 'P')
			(*p)++;
		i++;
	}
}

int	charcheck(char **ptr)
{
	int	i;
	int	c;
	int	p;
	int	e;

	if (!ptr)
		return (0);
	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (ptr[i])
	{
		ismapchr(ptr[i], &c, &e, &p);
		i++;
	}
	if (p != 1 || e != 1 || c == 0)
		return (0);
	return (c);
}

void	playerpos(char **ptr, int *y, int *x)
{
	while (ptr[*y])
	{
		*x = 0;
		while (ptr[*y][*x])
		{
			if (ptr[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	floodfill(char **ptr, int y, int x, int *c)
{
	if (ptr[y][x] == '1' || ptr[y][x] == 'X' || ptr[y][x] == 'E')
		return ;
	if (ptr[y][x] == 'C')
		(*c)++;
	ptr[y][x] = 'X';
	floodfill(ptr, y + 1, x, c);
	floodfill(ptr, y - 1, x, c);
	floodfill(ptr, y, x + 1, c);
	floodfill(ptr, y, x - 1, c);
	return ;
}

int	isaccess(char	**ptr)
{
	int	x;
	int	y;
	int	c;
	int	collectlen;

	x = 0;
	y = 0;
	c = 0;
	collectlen = charcheck(ptr);
	playerpos(ptr, &y, &x);
	floodfill(ptr, y, x, &c);
	if (c == collectlen)
		return (1);
	return (0);
}
