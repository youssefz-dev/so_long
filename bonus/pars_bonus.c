/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:15:40 by yzoullik          #+#    #+#             */
/*   Updated: 2025/02/11 15:27:45 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	parsmap(char *ptr)
{
	int		len;
	int		i;
	char	*ex;

	len = ft_strlen(ptr) - 1;
	ex = ".ber";
	i = 3;
	if (len > 3)
	{
		while (i >= 0)
		{
			if (ptr[len--] != ex[i--])
				return (0);
		}
		return (1);
	}
	return (0);
}

int	isrec(char **ptr)
{
	int		i;
	size_t	len;

	i = 0;
	if (ptr[i])
		len = ft_strlen(ptr[i]);
	while (ptr[i])
	{
		if (len != ft_strlen(ptr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ismap(char **ptr)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			k = 0;
			if (ptr[i][j] == '1' || ptr[i][j] == '0' || ptr[i][j] == 'C' \
				|| ptr[i][j] == 'E' || ptr[i][j] == 'P' || ptr[i][j] == 'M')
				k++;
			if (k == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	isclose(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[0][i])
		if (ptr[0][i++] != '1')
			return (0);
	i = 0;
	while (ptr[collen(ptr) - 1][i])
		if (ptr[collen(ptr) - 1][i++] != '1')
			return (0);
	i = 0;
	while (ptr[i])
	{
		if (ptr[i][0] != '1' || ptr[i][ft_strlen(ptr[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	pars(t_list **list)
{
	if (!list || !*list)
		return (write(2, "Error\nError in struct\n", 23), 0);
	if (!isrec((*list)->line))
		return (error(4, list), 0);
	if (!ismap((*list)->line))
		return (error(5, list), 0);
	if (!isclose((*list)->line))
		return (error(6, list), 0);
	if (!charcheck((*list)->line))
		return (error(7, list), 0);
	if (!isaccess((*list)->line))
		return (error(8, list), 0);
	return (1);
}
