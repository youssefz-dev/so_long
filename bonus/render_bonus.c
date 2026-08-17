/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:15:46 by yzoullik          #+#    #+#             */
/*   Updated: 2025/02/09 10:35:48 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clear_all(t_list **list)
{
	if ((*list)->line)
		ft_free((*list)->line);
	if ((*list)->mlx)
	{
		if ((*list)->wall)
			mlx_destroy_image((*list)->mlx, (*list)->wall);
		if ((*list)->space)
			mlx_destroy_image((*list)->mlx, (*list)->space);
		if ((*list)->coll)
			mlx_destroy_image((*list)->mlx, (*list)->coll);
		if ((*list)->exit)
			mlx_destroy_image((*list)->mlx, (*list)->exit);
		if ((*list)->player)
			mlx_destroy_image((*list)->mlx, (*list)->player);
		if ((*list)->monster)
			mlx_destroy_image((*list)->mlx, (*list)->monster);
		if ((*list)->win)
			mlx_destroy_window((*list)->mlx, (*list)->win);
		mlx_destroy_display((*list)->mlx);
		free((*list)->mlx);
	}
	if (*list)
		free(*list);
}

void	draw_map(t_list **list)
{
	int	y;
	int	x;
	int	(*p)(void *m, void *w, void *i, int x, int y);

	p = &mlx_put_image_to_window;
	y = 0;
	while ((*list)->line[y])
	{
		x = 0;
		while ((*list)->line[y][x])
		{
			draw(list, y, x);
			x++;
		}
		y++;
	}
}

void	ft_swap(char *curr, char *next, t_list **list)
{
	char	tmp;

	if (((*list)->coll_count == 0 && *next == 'E') || (*next == 'M'))
	{
		clear_all(list);
		exit(0);
	}
	if (*next == 'E')
		return ;
	if (*next == '1')
		return ;
	tmp = *curr;
	if (*next != 'C')
		*curr = *next;
	else
	{
		*curr = '0';
		(*list)->coll_count--;
	}
	++(*list)->counter;
	*next = tmp;
}

void	swap(char c, t_list **list)
{
	int		x;
	int		y;

	y = 0;
	playerpos((*list)->line, &y, &x);
	if (c == 'W')
		ft_swap(&(*list)->line[y][x], &(*list)->line[y - 1][x], list);
	if (c == 'A')
		ft_swap(&(*list)->line[y][x], &(*list)->line[y][x - 1], list);
	if (c == 'S')
		ft_swap(&(*list)->line[y][x], &(*list)->line[y + 1][x], list);
	if (c == 'D')
		ft_swap(&(*list)->line[y][x], &(*list)->line[y][x + 1], list);
	draw_map(list);
}

int	move(int key, t_list **list)
{
	if (key == 65307)
	{
		clear_all(list);
		exit(0);
	}
	if (key == 119)
		return (swap('W', list), 0);
	if (key == 97)
		return (swap('A', list), 0);
	if (key == 115)
		return (swap('S', list), 0);
	if (key == 100)
		return (swap('D', list), 0);
	return (0);
}
