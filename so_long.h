/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzoullik <yzoullik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:15:40 by yzoullik          #+#    #+#             */
/*   Updated: 2025/02/12 12:46:03 by yzoullik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

# define BUFFER_SIZE 42

typedef struct s_list
{
	void	*mlx;
	void	*win;
	char	**line;
	int		x;
	int		y;
	void	*wall;
	void	*space;
	void	*coll;
	void	*exit;
	void	*player;
	int		counter;
	int		coll_count;
}				t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s);
void	ft_free(char **ptr);

int		pars(t_list **list);
int		collen(char **ptr);
void	playerpos(char **ptr, int *x, int *y);
int		charcheck(char **ptr);
int		parsmap(char *ptr);
void	ft_putnbr(int n);
int		collen(char **ptr);
int		isaccess(char	**ptr);
int		move(int key, t_list **list);
void	draw_map(t_list **list);
int		error(int i, t_list **list);
int		ft_isaccess(char	**ptr);
void	clear_all(t_list **list);
void	ft_putchar(char c);
void	textures_init(t_list **list);
int		closew(t_list **list);

#endif