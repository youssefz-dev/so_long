/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:19:24 by yzoullik          #+#    #+#             */
/*   Updated: 2025/02/11 16:00:57 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_swap1(char *curr, char *next, t_list **list)
{
	char	tmp;

	if (*next == 'P')
	{
		clear_all(list);
		exit(0);
	}
	if (*next == 'E' || *next == 'C')
		return ;
	if (*next == '1')
		return ;
	tmp = *curr;
	*curr = *next;
	*next = tmp;
}

void	playerpos1(char **ptr, int *y, int *x)
{
	*y = 0;
	while (ptr[*y])
	{
		*x = 0;
		while (ptr[*y][*x])
		{
			if (ptr[*y][*x] == 'M')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	ai(t_list **list)
{
	int	x;
	int	y;
	int	i;
	int	j;

	playerpos((*list)->line, &y, &x);
	playerpos1((*list)->line, &j, &i);
	if (y < j)
		ft_swap1(&(*list)->line[j][i], &(*list)->line[j - 1][i], list);
	if (x < i)
		ft_swap1(&(*list)->line[j][i], &(*list)->line[j][i - 1], list);
	if (y > j)
		ft_swap1(&(*list)->line[j][i], &(*list)->line[j + 1][i], list);
	if (x > i)
		ft_swap1(&(*list)->line[j][i], &(*list)->line[j][i + 1], list);
}

void	animate(t_list **list, int *j)
{
	int			s;

	s = 64;
	ai(list);
	if (*j == 0)
	{
		mlx_destroy_image((*list)->mlx, (*list)->coll);
		(*list)->coll = mlx_xpm_file_to_image((*list)->mlx, \
		"./textures/CA.xpm", &s, &s);
		*j = 1;
	}
	else
	{
		mlx_destroy_image((*list)->mlx, (*list)->coll);
		(*list)->coll = mlx_xpm_file_to_image((*list)->mlx, \
		"./textures/C.xpm", &s, &s);
		*j = 0;
	}
	if (!(*list)->coll)
	{			
		error(-1, list);
		exit(1);
	}
}

int	anime(t_list **list)
{
	static int	i;
	static int	j;
	char		*ptr;

	ptr = ft_itoa((*list)->counter);
	if (!ptr)
		return (0);
	mlx_string_put((*list)->mlx, (*list)->win, (*list)->x / 2, 64, \
	16448250, ptr);
	free(ptr);
	if (i == 10000)
	{
		animate(list, &j);
		i = 0;
		draw_map(list);
	}
	i++;
	return (0);
}
