/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:42:35 by yzoullik          #+#    #+#             */
/*   Updated: 2025/02/09 14:29:14 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw(t_list **list, int y, int x)
{
	int	(*p)(void *m, void *w, void *i, int x, int y);

	p = &mlx_put_image_to_window;
	if ((*list)->line[y][x] == '1')
		p((*list)->mlx, (*list)->win, (*list)->wall, x * 64, y * 64);
	if ((*list)->line[y][x] == '0')
		p((*list)->mlx, (*list)->win, (*list)->space, x * 64, y * 64);
	if ((*list)->line[y][x] == 'P')
		p((*list)->mlx, (*list)->win, (*list)->player, x * 64, y * 64);
	if ((*list)->line[y][x] == 'E')
		p((*list)->mlx, (*list)->win, (*list)->exit, x * 64, y * 64);
	if ((*list)->line[y][x] == 'C')
		p((*list)->mlx, (*list)->win, (*list)->coll, x * 64, y * 64);
	if ((*list)->line[y][x] == 'M')
		p((*list)->mlx, (*list)->win, (*list)->monster, x * 64, y * 64);
}

void	ft_free(char **ptr)
{
	size_t	i;

	i = 0;
	if (ptr && ptr[i])
		while (ptr[i])
			free(ptr[i++]);
	if (ptr)
	{
		free(ptr);
		ptr = 0;
	}
}

static int	ft_intlen(long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (++i);
	if (nbr < 0)
		nbr *= -(++i);
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		ptrlen;
	long	nbr;

	nbr = n;
	ptrlen = ft_intlen(nbr);
	ptr = malloc(sizeof(char) * (ptrlen + 1));
	if (!ptr)
		return (NULL);
	if (nbr < 0)
		nbr *= -1;
	ptr[ptrlen--] = '\0';
	while (ptrlen >= 0)
	{
		ptr[ptrlen--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if (n < 0)
		ptr[0] = '-';
	return (ptr);
}

int	collen(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}
