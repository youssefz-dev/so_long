/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:25:42 by yzoullik          #+#    #+#             */
/*   Updated: 2025/02/12 12:38:10 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error(int i, t_list **list)
{
	write(2, "Error\n", 7);
	if (i == -1)
		write(2, "Invalid texture or error in mlx\n", 33);
	else if (i == 0)
		write(2, "Invalid arguments or error in file\n", 36);
	else if (i == 1)
		write(2, "Error with file descriptor\n", 28);
	else if (i == 2)
		write(2, "No map or unexpected new line in the first line\n", 49);
	else if (i == 3)
		write(2, "Unexpected new line in the map\n", 32);
	else if (i == 4)
		write(2, "Map is not rectangular\n", 24);
	else if (i == 5)
		write(2, "Invalid character\n", 19);
	else if (i == 6)
		write(2, "Map is not closed\n", 19);
	else if (i == 7)
		write(2, "Error in character\n", 20);
	else if (i == 8)
		write(2, "Player cannot access\n", 22);
	if (list)
		clear_all(list);
	return (0);
}

t_list	*list_init(char **ptr)
{
	t_list	*list;
	int		s;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	s = 64;
	list->mlx = mlx_init();
	list->win = 0;
	list->line = ft_split(*ptr);
	if (list->mlx)
		textures_init(&list);
	list->counter = 0;
	list->coll_count = 0;
	if (!list->line || !list->mlx || !list->wall || !list->space || \
	!list->coll || !list->exit || !list->player || !list->monster)
		return (error(-1, &list), free(*ptr), exit(1), NULL);
	list->x = 64 * ft_strlen(list->line[0]);
	list->y = 64 * collen(list->line);
	if (list->x > 2560 || list->y > 1440)
		return (error(-1, &list), free(*ptr), exit(1), NULL);
	return (list);
}

int	logic(t_list **list, char **str)
{
	*list = 0;
	*list = list_init(str);
	if (!pars(list))
		return (free(*str), 1);
	ft_free((*list)->line);
	(*list)->line = ft_split(*str);
	if (!(*list)->line || !ft_isaccess((*list)->line))
		return (free(*str), error(8, list));
	ft_free((*list)->line);
	(*list)->line = ft_split(*str);
	if (!(*list)->line)
		return (free(*str), error(8, list));
	free(*str);
	(*list)->coll_count = charcheck((*list)->line);
	(*list)->win = mlx_new_window((*list)->mlx, (*list)->x, (*list)->y, \
	"so_long");
	if (!(*list)->win)
		return (error(-1, list));
	draw_map(list);
	mlx_hook((*list)->win, 17, 1, closew, list);
	mlx_hook((*list)->win, 2, 1, move, list);
	mlx_loop_hook((*list)->mlx, anime, list);
	mlx_loop((*list)->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*list;
	char	*str;
	char	*ptr;
	int		fd;

	if (ac != 2 || !parsmap(av[1]))
		return (error(0, 0));
	str = 0;
	ptr = 0;
	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		return (error(1, 0));
	ptr = get_next_line(fd);
	if (!ptr || ptr[0] == '\n')
		return (close(fd), free(ptr), get_next_line(-10), error(2, 0));
	while (ptr)
	{
		str = ft_strjoin(str, ptr);
		free(ptr);
		ptr = get_next_line(fd);
		if (!str || (ptr && str[ft_strlen(str) - 1] == '\n' && ptr[0] == '\n'))
			return (close(fd), free(str), free(ptr), \
			get_next_line(-10), error(3, 0));
	}
	return (close(fd), logic(&list, &str));
}
