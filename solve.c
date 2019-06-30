/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:01:46 by sbudilko          #+#    #+#             */
/*   Updated: 2018/01/18 20:01:48 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_ischar(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int		ft_solve(char **map, t_tetromino *lst, int map_ln)
{
	int i;
	int j;

	i = -1;
	if (!lst)
	{
		ft_print_map(map);
		ft_clear_map(map);
		return (1);
	}
	while (++i <= map_ln - lst->x)
	{
		j = -1;
		while (++j <= map_ln - lst->y)
			if (ft_verif_2(map, lst, i, j) == 1)
				if (ft_solve(ft_put_tetro(ft_copy_map(map, map_ln), lst, i, j),
					lst->next, map_ln) == 1)
				{
					ft_clear_map(map);
					return (1);
				}
	}
	ft_clear_map(map);
	return (0);
}

char	**ft_put_tetro(char **map, t_tetromino *lst, int x_map, int y_map)
{
	int i;
	int j;

	i = 0;
	while (i < lst->x)
	{
		j = 0;
		while (j < lst->y)
		{
			if (map[x_map + i][y_map + j] == '.')
				map[x_map + i][y_map + j] = lst->figure[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

int		ft_verif_2(char **map, t_tetromino *lst, int x1, int y1)
{
	int i;
	int j;

	i = 0;
	while (i < lst->x)
	{
		j = 0;
		while (j < lst->y)
		{
			if (ft_ischar(map[x1 + i][y1 + j]) && ft_ischar(lst->figure[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_copy_map(char **map, int map_size)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = (char**)malloc(sizeof(new_map) * (map_size + 1));
	while (i < (map_size))
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
